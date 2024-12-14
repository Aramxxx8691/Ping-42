#ifndef FT_PING_H
# define FT_PING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>

# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[1;33m"
# define RESET  "\033[0;37m"
# define SKY    "\033[1;36m"

# define PING_PKT_SIZE 64

# define OPTION_COUNT 'c'
# define OPTION_HELP 'h'
# define OPTION_HOST 'H'
# define OPTION_INTERVAL 'i'
# define OPTION_SIZE 's'
# define OPTION_TIMEOUT 't'
# define OPTION_TIMESTAMP 'T'
# define OPTION_VERBOSE 'v'
# define OPTION_VERSION 'V'
# define OPTION_WAIT 'w'
# define OPTION_QUIET 'q'

# define USAGE RED "⚠️  Usage:" YELLOW " %s [option] host\n" RESET
# define INVALID_OPTION RED "❌ ping: invalid option --" SKY " '%c'\n" RESET
# define VALID_OPTION "?ctvhiHsTwqV"

# define DEBUG_OPT YELLOW "[DEBUG] " RESET "Resolving option: " SKY "%c\n" RESET
# define DEBUG_OPT_HOST YELLOW "[DEBUG] " RESET "Resolving host: " SKY "%s\n" RESET
# define DEBUG_HOST YELLOW "[DEBUG] " RESET "Host resolved: <IP address for " SKY "%s>\n" RESET
# define DEBUG_IPV4 YELLOW "[DEBUG] " RESET "Host is a valid IPv4 address: " SKY "%s\n" RESET
# define ERROR_IP RED "[ERROR] " RESET "ft_ping: " SKY "%s" RESET ": Name or service not known\n"

# define HELP_MESSAGE \
    YELLOW "Usage:\n" RESET \
    "  ft_ping [options] <destination>\n\n" \
    YELLOW "Options:\n" RESET \
    "  <destination>      DNS name or IP address\n" \
    "  -c <count>         Stop after <count> replies\n" \
    "  -h or -?           Print help and exit\n" \
    "  -i <interval>      Seconds between sending each packet\n" \
    "  -s <size>          Number of data bytes to send\n" \
    "  -t <timeout>       Timeout value in seconds\n" \
    "  -T                 Record timestamp\n" \
    "  -v                 Verbose output\n" \
    "  -V                 Print version and exit\n" \
    "  -w <wait>          Wait time before starting the ping\n" \
    "  -q                 Quiet mode (no output)\n" \
    "  -H <host>          Specify the host to ping\n\n" \
    YELLOW "For more details see ping(8).\n" RESET

typedef struct s_options
{
    int c;
    int h;
    int i;
    int s;
    int t;
    int T;
    int v;
    int V;
    int w;
    int q;
    char *host;
} t_options;

#endif