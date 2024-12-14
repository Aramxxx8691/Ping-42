
#include "../includes/ft_ping.h"

void    ft_parsing(int ac, char **av, t_options *opt)
{
    int i = 1;
    while (i < ac)
    {
        if (av[i][0] == '-')
        {
            if (strchr(VALID_OPTION, av[i][1]))
            {
                int index = strchr(VALID_OPTION, av[i][1]) - VALID_OPTION;
                int *fields[] = {&opt->c, &opt->t, &opt->v, &opt->h, &opt->i, &opt->s, &opt->T, &opt->V, &opt->w, &opt->q};
                *fields[index] = 1;
                printf(DEBUG_OPT, av[i][1]);
            
                if (av[i][1] == OPTION_HELP || av[i][1] == '?')
                {
                    printf(HELP_MESSAGE);
                    exit(0);
                }
            }
            else
            {
                printf(INVALID_OPTION, av[i][1]);
                exit(1);
            }
        }
        else
        {            
            opt->host = av[i];
            break;
        }
        i++;
    }
    if (!opt->host)
    {
        printf(USAGE, av[0]);
        exit(1);
    }
}

int is_valid_ipv4(const char *ip)
{
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr)) == 1;
}

// void    ft_host(t_options *opt)
// {
//     if (opt->v)
//         printf(DEBUG_OPT_HOST, opt->host);
//     if (is_valid_ipv4(opt->host))
//         printf(DEBUG_IPV4, opt->host);
//     else
//     {
//         struct sockaddr_in sa;
//         memset(&sa, 0, sizeof(sa));
//         if (inet_pton(AF_INET, opt->host, &(sa.sin_addr)) != 1)
//         {
//             printf(ERROR_IP, opt->host);
//         }
//         else
//         {
//             char ip[INET_ADDRSTRLEN];
//             inet_ntop(AF_INET, &(sa.sin_addr), ip, sizeof(ip));
//             printf(DEBUG_HOST, opt->host);
//         }
//     }
// }

void ft_host(t_options *opt)
{
    if (opt->v)
        printf(DEBUG_OPT_HOST, opt->host);
    if (is_valid_ipv4(opt->host))
    {
        if (opt->v)
            printf(DEBUG_IPV4, opt->host);
    }
    else
    {
        struct sockaddr_in sa;
        memset(&sa, 0, sizeof(sa));
        if (inet_pton(AF_INET, opt->host, &(sa.sin_addr)) != 1)
        {
            printf(ERROR_IP, opt->host);
            if (opt->v)
                printf(YELLOW "[DEBUG] " RESET "Error details: %s\n", strerror(errno));
        }
        else
        {
            char ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(sa.sin_addr), ip, sizeof(ip));
            if (opt->v)
                printf(YELLOW "[DEBUG] " RESET "Host resolved: " SKY "%s (%s)\n" RESET, opt->host, ip);
            else
                printf(DEBUG_HOST, opt->host);
        }
    }
}

int main(int ac, char **av)
{
    t_options opt = {0};
    if (ac < 2)
    {
        printf(USAGE, av[0]);
        return 1;
    }
    ft_parsing(ac, av, &opt);
    ft_host(&opt);
    return 0;
}
