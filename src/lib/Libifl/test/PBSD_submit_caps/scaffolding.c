#include "license_pbs.h" /* See here for the software license */
#include <stdlib.h>
#include <stdio.h> /* fprintf */

#include "libpbs.h" /* connect_handle, batch_reply */
#include "u_hash_map_structs.h" /* job_data */
#include "attribute.h" /* attropl */

struct connect_handle connection[10];
char pbs_current_user[PBS_MAXUSER];
const char *dis_emsg[10];


ssize_t read_nonblocking_socket(int fd, void *buf, ssize_t count)
  {
  fprintf(stderr, "The call to read_nonblocking_socket needs to be mocked!!\n");
  exit(1);
  }

int encode_DIS_JobId(struct tcp_chan *chan, char *jobid)
  {
  fprintf(stderr, "The call to encode_DIS_JobId needs to be mocked!!\n");
  exit(1);
  }

int encode_DIS_JobFile(struct tcp_chan *chan, int seq, char *buf, int len, char *jobid, int which)
  {
  fprintf(stderr, "The call to encode_DIS_JobFile needs to be mocked!!\n");
  exit(1);
  }

struct tcp_chan *DIS_tcp_setup(int fd)
  {
  fprintf(stderr, "The call to DIS_tcp_setup needs to be mocked!!\n");
  exit(1);
  }

int encode_DIS_QueueJob(struct tcp_chan *chan, char *jobid, char *destin, struct attropl *aoplp)
  {
  fprintf(stderr, "The call to encode_DIS_QueueJob needs to be mocked!!\n");
  exit(1);
  }

int DIS_tcp_wflush(tcp_chan *chan)
  {
  fprintf(stderr, "The call to DIS_tcp_wflush needs to be mocked!!\n");
  exit(1);
  }

struct batch_reply *PBSD_rdrpy(int *local_errno, int c)
  {
  fprintf(stderr, "The call to PBSD_rdrpy needs to be mocked!!\n");
  exit(1);
  }

int encode_DIS_QueueJob_hash(struct tcp_chan *chan, char *jobid, char *destin, job_data_container *job_attr, job_data_container *res_attr)
  {
  fprintf(stderr, "The call to encode_DIS_QueueJob_hash needs to be mocked!!\n");
  exit(1);
  }

void PBSD_FreeReply(struct batch_reply *reply)
  {
  fprintf(stderr, "The call to PBSD_FreeReply needs to be mocked!!\n");
  exit(1);
  }

int encode_DIS_ReqExtend(struct tcp_chan *chan, char *extend)
  {
  fprintf(stderr, "The call to encode_DIS_ReqExtend needs to be mocked!!\n");
  exit(1);
  }

int encode_DIS_ReqHdr(struct tcp_chan *chan, int reqt, char *user)
  {
  fprintf(stderr, "The call to encode_DIS_ReqHdr needs to be mocked!!\n");
  exit(1);
  }


void DIS_tcp_cleanup(struct tcp_chan *chan)
  {
  }

ssize_t read_ac_socket(int fd, void *buf, ssize_t count)
  {
  return(0);
  }
