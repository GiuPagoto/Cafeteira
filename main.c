//------------------------------------------------------------------------------------- //
//		AVR e Arduino: Técnicas de Projeto, 2a ed. - 2012.								//	
//------------------------------------------------------------------------------------- //
//=====================================================================================	//
//		ACIONANDO UM DISPLAY DE CRISTAL LIQUIDO DE 16x2									//
//			programa cafeteira utilizando timer 0																			//
//				, maquina de estados e funcoes											//
//				GRUPO WINX: GIULLIA, HELOISA, LUCINARIA												//
//=====================================================================================	//
#include <avr/interrupt.h>
#include "def_principais.h"			//inclusão do arquivo com as principais definições 
#include "LCD.h"
#include "variaveis.h"
#include "funcoes_maquina_lavar.h"

ISR(TIMER0_OVF_vect)					//interrupção do TC0
{   TCNT0=100; // 156 contagens equivalem a 10ms em 16mhz
	if(tempo) {   tempo--; 
  		          if(estado>8 && estado <13)
			         {
			          cmd_LCD(0x8D,0);     
		              ident_num(tempo/100,digitos);
		              cmd_LCD(digitos[2],1);
		              cmd_LCD(digitos[1],1);
		              cmd_LCD(digitos[0],1);
				     }
	          }
}

int main()
{		//declaração da variável para armazenagem dos digitos
	DDRB = 0b11111111;			//PB0 como pino de entrada, os demais pinos como saída
	PORTB= 0b11000011;				//habilita o pull-up do PB0		 
	DDRD = 0xFF;				//PORTD como saída (display)
	PORTD= 0xFF;				//desliga o display
	UCSR0B = 0x00;				//PD0 e PD1 como I/O genérico, para uso no Arduino
    DDRC= 0b00000000;  // saidas motor e valvulas
    PORTC= 0b11111111;
	inic_LCD_4bits();				//inicializa o LCD
	cmd_LCD(0x01,0); 				//desloca cursor para a segunda linha
	configura_temporizacao();
    tempo=150;  // tempo aguardar
while(1) 					//laço infinito
 { 
   switch(estado) 
   {
   case 1:   cmd_LCD(0x80,0);	escreve_LCD_Flash(msg_bemvindo); //pressionado=0;	
             if(!tempo) {  estado++; cmd_LCD(0x01,0);  }   break;  //
   case 2:  configura_tamanho();       break; //	 
   case 3:  configura_leite();         break; // 
   case 4:  configura_cafe();      break; //  	 
   case 5:  configura_capuccino(); break; //  
   case 6:  configura_acucar();   break; //  
   case 7:  presenca(); break;
   case 8:  inicializando(); break;
   case 9:  processo_leite();  break;  // enchendo
   case 10:  processo_cafe(); break; //agitacao 1
   case 11:  processo_capuccino();  break; // molho 1	   
   case 12: processo_acucar(); break; //agitacao 2  
   case 13: presenca_fim(); break;
   case 14: reinicializando(); break; // reinicializando	
   
  
   }   // fim switch
  }//fim while
} // fim main
