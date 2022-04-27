#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#define MAXPENDING 5 //연결요청 대기할 수 있는 최대수 
#define RCVBUFSIZE 32

void DieWithError(char *errorMessage);
void HandleTCPClient(int clntSocket);

int main(int argc, char *argv[])
{
    int servSock; //서버소켓 //tcp 소켓의 종류
    int clntSock; //클라이언트 소켓
    struct sockaddr_in echoServAddr; //지역주소 //sockaddr_in 소켓의 구성요소를 담을 구조체
    struct sockaddr_in echoClntAddr; //연결되어있는 주소 
    unsigned short echoServPort;//에코서버
    unsigned int clntLen;

    if (argc != 2)//argc는0이 되지않음 즉 항상 1, 명령어 인자의 개수 확인 
    {
        fprintf(stderr, "Usage: %s <Server Port>\n", argv[0]);//argv[0]입력한 프로그램의 경로와 이름 즉, argv는 옵션의 개수가 저장
        exit(1);
    }
    else
    {
        fprintf(stderr, "%s\n", argv[0]);
    }

    echoServPort = atoi(argv[1]); //argv[1] 지향매개변수 para문자열 , 첫번째 인자: 지역포트 

    //연결요청 처리하는 소켓 생성 

    if ((servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket() failed"); //socket 열기

    printf("servSock = %d\n", servSock);
    
    //지역주소 구조체 생성 
    memset(&echoServAddr, 0, sizeof(echoServAddr)); //0으로 구조체 초기화
    echoServAddr.sin_family = AF_INET;              // IPv4 주소 패밀리 32비트 (4바이트)
    echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY); //호스트의 어떠한 IP로도 연결 요청 수락, 현재 동작되는 컴퓨터 ip주소 설정 
    echoServAddr.sin_port = htons(echoServPort); //소켓에 bind, 지역 포트 


    //지역주소에 bind 
    if (bind(servSock, (struct sockaddr *)&echoServAddr, sizeof(echoServAddr)) < 0) //소켓 주소정보를 묶어줌 
        DieWithError("bind() failed"); //bind 실패했을 때 에러처리

    //소켓이 들어오는 요청을 처리할 수 있도록 설정 
    if (listen(servSock, MAXPENDING) < 0) //MAXPENDING (한꺼번에 요청 가능한 최대 접속 승인 수 )
        DieWithError("listen() failed"); //socket상태를 listen으로 만든다. (listen 소켓이 접속)

    fprintf(stderr, "server ready \n"); //accept 전  

    for (;;) //초기값, 조건식, 변화식 모두 생략해서 무한루프 
    {
        clntLen = sizeof(echoClntAddr); //클라이언트 주소 

        //clntSock가 클라이언트와 연결됨 
        if ((clntSock = accept(servSock, (struct sockaddr *)&echoClntAddr, &clntLen)) < 0)
            DieWithError("accept() failed"); //액션 accept 에러처리 접속 요청을 허락해즘 , 동기화 방식 이용, 요청승인시 연결된 소켓이 만들어져서 리턴됨

        printf("Handling client %s\n", inet_ntoa(echoClntAddr.sin_addr));
        printf("start\n");//chating start

        //inet_ntoa 네트워크 바이트 순서 32비트 값을 dotted-decimal notation 주소값으로 변환 

        HandleTCPClient(clntSock);
    } //클라이언트에서 해당 ip,port로 connect, 실행되지 않음

    close(servSock);
}

void DieWithError(char *errorMessage)//error function
{
    perror(errorMessage);
    exit(1);
}
    // handle tcp client 로 따로 빼기도 함
    void HandleTCPClient(int clntSocket)
{
    char echoBuffer[RCVBUFSIZE]; // buffer for echo string
    int recvMsgSize;

    if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0) //보낼 소켓, 받아올 변수 , 데이터 크기, 플래그 
        DieWithError("recv() failed");

    fprintf(stderr, "echoBuffer = %s \n", echoBuffer); //recv , send 순으로 (이거는 client)
    fprintf(stderr, "recvMsgSize = %d \n", recvMsgSize);

    while (recvMsgSize > 0)
    {
        if (send(clntSocket, echoBuffer, recvMsgSize, 0) != recvMsgSize)
            DieWithError("send() failed");

        if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
            DieWithError("recv() failed");
    } //클라이언트 액션 받아주고 프로토콜을 데이터로 주고 받는다

    close(clntSocket);
    printf("close connection\n");
} //사용다했으면 close해 줌 


