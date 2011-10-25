#!/usr/bin/perl

use strict;
use warnings;

use FindBin;
use TestLibFinder;
use lib test_lib_loc();


# Test Modules
use CRI::Test;

use Torque::Job::Ctrl           qw(
                                    submitSleepJob
                                    runJobs
                                    delJobs
                                  );
use Torque::Util         qw( run_and_check_cmd 
                                    list2array        );
use Torque::Util::Qstat  qw( qstat_fx    );

# Test Description
plan('no_plan');
setDesc("qalter -p");

# Variables
my $p_cmd;
my $fx_cmd;
my $qstat;
my $qstat_fx;
my %qalter;
my $job_id;
my $priority;

# Submit the jobs
my $job_params = {
                   'user'       => $props->get_property('User.1'),
                   'torque_bin' => $props->get_property('Torque.Home.Dir') . '/bin/'
                 };

$job_id = submitSleepJob($job_params);

# Run a job
runJobs($job_id);

# Check qalter -p positive boundry 
$priority  = 1023; # This should pass
$p_cmd     = "qalter -p $priority $job_id";
%qalter    = run_and_check_cmd($p_cmd);

$fx_cmd   = "qstat -f -x $job_id";

$qstat_fx = qstat_fx({job_id => $job_id});
ok($qstat_fx->{ $job_id }{ 'priority' } eq $priority, "Checking if '$p_cmd' was successful");

$priority  = 1024; # This should fail
$p_cmd     = "qalter -p $priority $job_id";
%qalter    = runCommand($p_cmd);
ok((    defined $qalter{ 'STDERR' } 
    and $qalter{ 'STDERR' } =~ /qalter: illegal -p value/), 
   "Checking for failure of '$p_cmd'");

# Check qalter -p negative boundry 
$priority  = -1024; # This should pass
$p_cmd     = "qalter -p $priority $job_id";
%qalter    = run_and_check_cmd($p_cmd);

$fx_cmd   = "qstat -f -x $job_id";

$qstat_fx = qstat_fx({job_id => $job_id});
ok($qstat_fx->{ $job_id }{ 'priority' } eq $priority, "Checking if '$p_cmd' was successful");

$priority  = -1025; # This should fail
$p_cmd     = "qalter -p $priority $job_id";
%qalter    = runCommand($p_cmd);
ok((    defined $qalter{ 'STDERR' } 
    and $qalter{ 'STDERR' } =~ /qalter: illegal -p value/), 
   "Checking for failure of '$p_cmd'");

# Delete the jobs
delJobs($job_id);