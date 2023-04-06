//saidas
//#define motoragitacao   PB4
#define valvula_leite PB5
#define valvula_cafe PB4
#define valvula_capuccino PB3
#define valvula_acucar PB2
//#define valvulaesvaziar PB2


//entradas
#define  ENTER PC2
#define  MENOS PC1
#define  MAIS PC0
#define  sensor_presenca PC4
//#define  sensorcheio PC3


// variaveis
unsigned int tempo=0; 
unsigned char tempo_tamanho=3;
unsigned char  estado=1, menu1=1, menu2=1, menu3=1, menu4=1, menu5=1, copo=1, leite=1, cafe=1, capuccino=1, acucar=1;	//declara variável global

volatile  unsigned char conta;

unsigned char digitos[tam_vetor];
//volatile unsigned char segundos, minutos, horas;

PROGMEM const char msg_processo_leite[] = "Leite  \0" ; //mensagem armazenada na memória flash
PROGMEM const char msg_processo_cafe[] = "Cafe  \0" ; //mensagem armazenada na memória flash
PROGMEM const char msg_processo_capuccino[] = "Capuccino  \0" ; //mensagem armazenada na memória flash
PROGMEM const char msg_processo_acucar[] = "Acucar  \0" ; //mensagem armazenada na memória flash
PROGMEM const char msg_presenca[] = "Copo detectado  \0" ; //mensagem armazenada na memória flash
PROGMEM const char msg_sem_copo[] = "Copo retirado  \0" ; //mensagem armazenada na memória flash
PROGMEM const char msg_insira_o_copo[] = "Insira o copo  \0" ; //mensagem armazenada na memória flash
PROGMEM const char msg_retire_o_copo[] = "retire o copo  \0" ; //mensagem armazenada na memória flash
PROGMEM const char msg_sim[] = "sim       \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_nao[] = "nao        \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_configura_leite[] = "Escolha leite         \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_configura_cafe[] = "Escolha cafe         \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_configura_capuccino[] = "Escolha capuccino        \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_configura_acucar[] = "Escolha acucar        \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_medio[] = "Copo medio         \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_pequeno[] = "Copo pequeno           \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_tamanho[] = "Escolha Tamanho:            \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_bemvindo[] = "Bem vindo !!!            \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_inicializando[] = "Em processo....   \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_fim[] = "Fim do processo      \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_reiniciando[] = "Reiniciando....  \0"; //mensagem armazenada na memória flash
