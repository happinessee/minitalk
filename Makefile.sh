rm -f client server;
cc -o client -Wall -Wextra -Werror ft_client.c write_func.c minitalk_utils.c -I .;
cc -o server -Wall -Wextra -Werror ft_server.c write_func.c minitalk_utils.c -I .