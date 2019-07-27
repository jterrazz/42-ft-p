# 42-ft-p
Client and server implementation allowing file transfers on TCP/IP

Install official ftp cmd line tool on mac:
```
brew install inetutils
```

Simulate a socket server using TCP/IP
```
nc -l 2399
```
Check get next line is used
TCP sockets.
Notions
- Multiple clients with fork(2)
- Systeme calls: socket(2), qman
- Byte compatibilty: htons(3), htonl(3), ntohs(3), ntohl(3)q
- Transfers: send(2), recv(2), execv(2), execl(2), dup2(2), wait4(2)
- TCP/IP transfers
- client / server connection
- Prompt specific
- Transfer of error messages
- Keep process alive with instructions

Explain all functions used and their utility

Bonus possibles
- Different directory per login
- IPV6
- mget/mput with *
- login/password
- mkdir / rmdir

Ressources
https://tools.ietf.org/html/rfc959.html
