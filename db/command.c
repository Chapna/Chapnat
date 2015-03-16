/*
 * In The Name Of God
 * ========================================
 * [] File Name : command.c
 *
 * [] Creation Date : 30-12-2014
 *
 * [] Last Modified : Wed Jan 28 14:21:10 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <string.h>
#include <stdio.h>

#include "message.h"
#include "users.h"
#include "command.h"
#include "net.h"

void signin_command(const struct message *message, int socket_fd)
{
	add_user(message, socket_fd);
}

void leave_command(const struct message *message, int socket_fd)
{
}

void send_command(const struct message *message, int socket_fd)
{
	snd_user(message, socket_fd);
}

void check_command(const struct message *message, int socket_fd)
{
}

void command_dispatcher(int socket_fd, const struct message *message)
{
	if (!strcmp(message->verb, "signin"))
		signin_command(message, socket_fd);
	else if (!strcmp(message->verb, "leave"))
		leave_command(message, socket_fd);
	else if (!strcmp(message->verb, "send"))
		send_command(message, socket_fd);
	else if (!strcmp(message->verb, "check"))
		check_command(message, socket_fd);
}
