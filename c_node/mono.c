/* mono.c: mono-threaded c node */
#include <stdio.h>       /* printf */
#include <string.h>      /* strcmp, strncmp, memset */
#include <strings.h>     /* bzero */
#include <stdlib.h>      /* */
#include <sys/types.h>   /* */
#include <sys/socket.h>  /* */
#include <netinet/in.h>  /* */
#include "shared.h"

struct state {
	int port;
	int sock;
	int listen;
	struct sockaddr addr;
};

int state_init(struct state*);
int connection_init(struct state*);
void debug(char *, ...);

int
state_init(struct state *state) {
	state->port = 0;
	state->sock = 0;
	state->listen = 0;
	bzero(&state->addr, sizeof(state->addr));
	return 0;
}

int
connection_init(struct state *state) {
	int rsock = socket(AF_INET, SOCK_STREAM, 0);
	if (rsock<0)
		state->sock = rsock;
	else
		return -1;

	int rlisten = listen(state->sock, 5);
	if (rlisten<0)
		state->listen = rlisten;
	else
		return -1;

	return 0;
}

int 
main(void) {
	struct state state;
	state_init(&state);
}
