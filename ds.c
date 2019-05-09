
static void *process_queue(void *soap);

static int enqueue(struct cntb_soap_server *hndl, struct soap_proc *soap);

static struct soap_proc dequeue(struct cntb_soap_server *hndl);

struct cntb_soap_server *cntb_soap_server_create(
        struct cntb_soap_server_param *param)
{
    if(!param || !param->station || !param->sc) return NULL;

    struct cntb_soap_server *hndl = (struct cntb_soap_server *)malloc(
            sizeof(*hndl));
    if(!hndl) return NULL;
    memset(hndl, 0, sizeof(*hndl));
    hndl->listen_port = param->listen_port;
    hndl->station = param->station;
    hndl->sc = param->sc;
    hndl->log_hndl = param->log_hndl;