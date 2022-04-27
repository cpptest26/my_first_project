#include <stdio.h>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RCVBUFSIZE 32//size of receive buffer

void DieWithError(char *errorMessage);//error handling function

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in echoServAddr;//echo server address
    unsigned short echoServPort;//echo server port
    char *servIP; //첫번째 인자 서버 ip주소
    char *echoString; //두번째 인자 보내려는 에코 문자열
    char echoBuffer[RCVBUFSIZE]; //buffer for echo string
    unsigned int echoStringLen; //lenght of string to echo 
    int bytesRcvd, totalBytesRcvd;//bytes read in single recv() and total bytes read

    if ((argc < 3) || (argc > 4)) //명령어 인자의 정확한 개수 확인 
    {
        fprintf(stderr, "Usage; %s <Server IP> <Echo Word> [<Echo Port>]\n", argv[0]);
        exit(1);
    }

    servIP = argv[1]; // first arg : server ip address
    echoString = argv[2]; //second arg : string to echo

    if (argc == 4) //세번째 인자 선택 서버포트 (숫자형식) 7이 잘 알려진 포트로 생략시 7을 사용 
        echoServPort = atoi(argv[3]); //use giver port if any
    else
        echoServPort = 7; //서버 소켓 

    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) //tcp를 사용하여 안정된 스트림 소켓 생성 
        DieWithError("socket() failed");//constryct the server address structure

    //서버 주소 구조체 생성 
    memset(&echoServAddr, 0, sizeof(echoServAddr)); //0으로 구조체 초기화
    echoServAddr.sin_family = AF_INET; //IPV4주소 초기화 internet address family
    echoServAddr.sin_addr.s_addr = inet_addr(servIP); //server ip address
    echoServAddr.sin_port = htons(echoServPort); //서버포트 

    //에코 서버에 연결 성정 
    if (connect(sock, (struct sockaddr *)&echoServAddr, sizeof(echoServAddr)) < 0) //client connect
        DieWithError("connect) failed");

    echoStringLen = strlen(echoString); //입력받은 문자열의 길이 확인 

    if (send(sock, echoString, echoStringLen, 0) != echoStringLen) //send
        DieWithError("send() sent a different number of bytes than expected");

    //서버로부터 동일한 문자열 수신 
    totalBytesRcvd = 0; //수신한 문자 개수 
    printf("Received: ");// 돌려받은 에코 문자열 출력을 위한 설정
    while (totalBytesRcvd < echoStringLen)//recv 한 거 비교 
    {
        if ((bytesRcvd = recv(sock, echoBuffer, RCVBUFSIZE - 1, 0)) <= 0) //입출력 버터 버퍼크기만큼 서버로부터 수신 (널문자위해 1바이트 남겨놓음 )
            DieWithError("recv() failed or connection closed promaturely");
        totalBytesRcvd += bytesRcvd; //총 받은 크기를 기록 
        echoBuffer[bytesRcvd] = '\0'; //널문자를 추가하여 문자열 완성
        printf(echoBuffer); //에코버퍼를 출력 
    }

    printf("\n"); //개행문자 출력 (linefeed)

    close(sock);//close 
    exit(0);
}

void DieWithError(char *errorMessage)
{
    perror(errorMessage);
    exit(1);
}
