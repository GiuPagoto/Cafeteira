
//menus
void configura_tamanho(); //menu1
void configura_leite(); //menu2
void configura_cafe(); //menu3
void configura_capuccino(); //menu4
void configura_acucar(); //menu5

//processo
void presenca();
void inicializando();
void processo_leite();
void processo_cafe();
void processo_capuccino();
void processo_acucar();
void presenca_fim();
void reinicializando (); 

//ESCOLHER TAMANHO
void configura_tamanho()
 { 
	 cmd_LCD(0x80,0); //inicializa cursor na primeira posição a esquerda - 1a linha 
	 escreve_LCD_Flash(msg_tamanho); 

	switch(menu1)
	{
		case 1: //2 opcoes de copo
		cmd_LCD(0xC0,0); //mensagem aparente cursor inativo não piscando 
		escreve_LCD_Flash(msg_pequeno);
		copo=1; //copo pequeno
		tempo_tamanho = 3;
		break;
		
		case 2:
		cmd_LCD(0xC0,0); //mensagem aparente cursor inativo não piscando 
		escreve_LCD_Flash(msg_medio);
		copo=2; //copo medio
		tempo_tamanho = 5;
		break;
	}//end switch
		
		
		if(!tst_bit(PINC,0)) //botao mais
		{ 
			if(menu1==2)
			{
				menu1=1;
				_delay_ms(300);
			}
			else
			{
				menu1++;
				_delay_ms(300);
			}
		}
		
		if(!tst_bit(PINC,1)) //botao menos
		{
			if(menu1==1)
			{
				menu1=2;
				_delay_ms(300);
			}
			else
			{
				menu1--;
				_delay_ms(300);
			}
		}
		
		if(!tst_bit(PINC,2)) //botao enter
		{
			estado=3;
			_delay_ms(300);
			cmd_LCD(0x01,0); //limpa todo o display 
		}	
		 //end botao enter 
 } //end void
 
 //ESCOLHER LEITE
 void configura_leite()
 { 
	 cmd_LCD(0x80,0); //inicializa cursor na primeira posição a esquerda - 1a linha 
	 escreve_LCD_Flash(msg_configura_leite); 

	switch(menu2)
	{
		case 1: //com leite
		cmd_LCD(0xC0,0);  //mensagem aparente cursor inativo não piscando 
		escreve_LCD_Flash(msg_sim);
		leite=1; //com leite
		break;
		
		case 2://sem leite
		cmd_LCD(0xC0,0);  //mensagem aparente cursor inativo não piscando 
		escreve_LCD_Flash(msg_nao);
		leite=2; //sem leite
		break;
	} //end switch
		
		if(!tst_bit(PINC,0)) //botao mais
		{
			if(menu2==2)
			{
				menu2=1;
				_delay_ms(300);
			}
			else
			{
				menu2++;
				_delay_ms(300);
			}
		}
		
		if(!tst_bit(PINC,1)) //botao menos
		{
			if(menu2==1)
			{
				menu2=2;
				_delay_ms(300);
			}
			else
			{
				menu2--;
				_delay_ms(300);
			}
		}
		
		if(!tst_bit(PINC,2)) //botao enter
		{
			estado=4;
			_delay_ms(300);
			cmd_LCD(0x01,0);  //limpa todo o display 
			
		} //end botao enter
 } //end void
 
 //ESCOLHER CAFE
 void configura_cafe()
 {
	cmd_LCD(0x80,0); //inicializa cursor na primeira posição a esquerda - 1a linha 
	escreve_LCD_Flash(msg_configura_cafe); 
	
 	switch(menu3)
	{
		case 1: //com cafe
		cmd_LCD(0xC0,0);  //mensagem aparente cursor inativo não piscando 
		escreve_LCD_Flash(msg_sim);
		cafe=1; //com cafe
		break;
		
		case 2://sem cafe
		cmd_LCD(0xC0,0);  //mensagem aparente cursor inativo não piscando 
		escreve_LCD_Flash(msg_nao);
		cafe=2; //sem cafe
		break;
	} //end switch
		
		if(!tst_bit(PINC,0)) //botao mais
		{
			if(menu3==2)
			{
				menu3=1;
				_delay_ms(300);
			}
			else
			{
				menu3++;
				_delay_ms(300);
			}
		}
		
		if(!tst_bit(PINC,1)) //botao menos
		{
			if(menu3==1)
			{
				menu3=2;
				_delay_ms(300);
			}
			else
			{
				menu3--;
				_delay_ms(300);
			}
		}
		
		if(!tst_bit(PINC,2)) //botao enter
		{
			estado=5;
			_delay_ms(300);
			cmd_LCD(0x01,0); //limpa todo o display
			
		} //end botao enter
 } //end void
 
 //ESCOLHER CAPUCCINO
 void configura_capuccino()	
{
	cmd_LCD(0x80,0); //inicializa cursor na primeira posição a esquerda - 1a linha
	escreve_LCD_Flash(msg_configura_capuccino); 
	
	switch(menu4)
	{
		case 1: //com capuccino
		cmd_LCD(0xC0,0);  //mensagem aparente cursor inativo não piscando 
		escreve_LCD_Flash(msg_sim);
		capuccino=1; //com capuccino
		break;
		
		case 2://sem capuccino
		cmd_LCD(0xC0,0);  //mensagem aparente cursor inativo não piscando 
		escreve_LCD_Flash(msg_nao);
		capuccino=2; //sem capuccino
		break;
	} //end switch
		
		if(!tst_bit(PINC,0)) //botao mais
		{
			if(menu4==2)
			{
				menu4=1;
				_delay_ms(300);
			}
			else
			{
				menu4++;
				_delay_ms(300);
			}
		}
		
		if(!tst_bit(PINC,1)) //botao menos
		{
			if(menu4==1)
			{
				menu4=2;
				_delay_ms(300);
			}
			else
			{
				menu4--;
				_delay_ms(300);
			}
		}
		
		if(!tst_bit(PINC,2)) //botao enter
		{
			estado=6;
			_delay_ms(300);
			cmd_LCD(0x01,0); //limpa todo o display 
			
		} //end botao enter
 } //end void
 
 //ESCOLHER ACUCAR
  void configura_acucar()
  {
	cmd_LCD(0x80,0); //inicializa cursor na primeira posição a esquerda - 1a linha
	escreve_LCD_Flash(msg_configura_acucar); 
	
  	switch(menu5)
	{
		case 1: //com acucar
		cmd_LCD(0xC0,0); //limpa todo o display
		escreve_LCD_Flash(msg_sim);
		acucar=1; //com acucar
		break;
		
		case 2://sem acucar
		cmd_LCD(0xC0,0); //limpa todo o display
		escreve_LCD_Flash(msg_nao);
		acucar=2; //sem acucar
		break;
	} //end switch
		
		if(!tst_bit(PINC,0)) //botao mais
		{
			if(menu5==2)
			{
				menu5=1;
				_delay_ms(300);
			}
			else
			{
				menu5++;
				_delay_ms(300);
			}
		}
		
		if(!tst_bit(PINC,1)) //botao menos
		{
			if(menu5==1)
			{
				menu5=2;
				_delay_ms(300);
			}
			else
			{
				menu5--;
				_delay_ms(300);
			}
		}
		
		if(!tst_bit(PINC,2)) //botao enter
		{
			estado=7;
			_delay_ms(300);
			cmd_LCD(0x01,0); //limpa todo o display 
		} //end botao enter
 } //end void
 
void presenca()
{
	cmd_LCD(0x80,0); //inicializa cursor na primeira posição a esquerda - 1a linha 
	escreve_LCD_Flash(msg_insira_o_copo);
			
	if(!tst_bit(PINC,3)) 
	{ 
		cmd_LCD(0x80,0); //inicializa cursor na primeira posição a esquerda - 1a linha 
		escreve_LCD_Flash(msg_presenca);
		_delay_ms(500);
		cmd_LCD(0x80,0); //inicializa cursor na primeira posição a esquerda - 1a linha 
		escreve_LCD_Flash(msg_inicializando);
		estado=8;
		tempo = tempo_tamanho*100;
	}
}

void inicializando()
{
	if(!tempo)
	{
		estado=9;
		tempo = tempo_tamanho*100;
		cmd_LCD(0xC0,0); //mensagem aparente cursor inativo não piscando
		escreve_LCD_Flash(msg_processo_leite);
	}
}

//VALVULA LEITE
void processo_leite()
{
	if(leite==1) //com leite
	{
		set_bit(PORTB,valvula_leite);
		if(!tempo)
		{
			clr_bit(PORTB,valvula_leite);
			estado=10;
			tempo = tempo_tamanho*100;
			cmd_LCD(0xC0,0); //mensagem aparente cursor inativo não piscando
			escreve_LCD_Flash(msg_processo_cafe);
		}
	}
	
	else //sem leite
	{
		clr_bit(PORTB,valvula_leite);
		if(!tempo)
		{
			//clr_bit(PORTB,valvula_leite);
			estado=10;
			tempo = tempo_tamanho*100;
			cmd_LCD(0xC0,0); //mensagem aparente cursor inativo não piscando
			escreve_LCD_Flash(msg_processo_cafe);
		}
	}	
}


//VALVULA CAFE
void processo_cafe(){
		
	if(cafe==1) //com cafe
	{
		set_bit(PORTB,valvula_cafe);
		if(!tempo)
		{
			clr_bit(PORTB,valvula_cafe);
			estado=11;
			tempo = tempo_tamanho*100;
			cmd_LCD(0xC0,0); //mensagem aparente cursor inativo não piscando
			escreve_LCD_Flash(msg_processo_capuccino);
		}
	}
		
	else //sem cafe
	{
		clr_bit(PORTB,valvula_cafe);
		if(!tempo)
		{
			//clr_bit(PORTB,valvula_cafe);
			estado=11;
			tempo = tempo_tamanho*100;
			cmd_LCD(0xC0,0); //mensagem aparente cursor inativo não piscando
			escreve_LCD_Flash(msg_processo_capuccino);
		}
	}	
}

//VALVULA CAPUCCINO
void processo_capuccino(){
	
	if(capuccino==1) //com capuccino
	{
		set_bit(PORTB,valvula_capuccino);
		if(!tempo)
		{
			clr_bit(PORTB,valvula_capuccino);
			estado=12;
			tempo = tempo_tamanho*100;
			cmd_LCD(0xC0,0); //mensagem aparente cursor inativo não piscando
			escreve_LCD_Flash(msg_processo_acucar);
		}
	}
	
	else //sem capuccino
	{
		clr_bit(PORTB,valvula_capuccino);
		if(!tempo)
		{
			//clr_bit(PORTB,valvula_capuccino);
			estado=12;
			tempo = tempo_tamanho*100;
			cmd_LCD(0xC0,0); //mensagem aparente cursor inativo não piscando
			escreve_LCD_Flash(msg_processo_acucar);
		}
	}	
}

void processo_acucar(){
	
	if(acucar==1) //com acucar
	{
		set_bit(PORTB,valvula_acucar);
		if(!tempo)
		{
			clr_bit(PORTB,valvula_acucar);
			estado=13;
			tempo = tempo_tamanho*100;
			cmd_LCD(0x01,0); //limpa todo o display
			//cmd_LCD(0x80,0); //inicializa cursor na primeira posição a esquerda - 1a linha
			//escreve_LCD_Flash(msg_fim);
		}
	}
		
	else //sem acucar
	{
		clr_bit(PORTB,valvula_acucar);
		if(!tempo)
		{
			//clr_bit(PORTB,valvula_acucar);
			estado=13;
			tempo = tempo_tamanho*100;
			cmd_LCD(0x01,0); //limpa todo o display
			//cmd_LCD(0x80,0); //inicializa cursor na primeira posição a esquerda - 1a linha
			//escreve_LCD_Flash(msg_fim);
			
		}
		
	}
	
}

void presenca_fim()
{
	cmd_LCD(0x80,0); //inicializa cursor na primeira posição a esquerda - 1a linha
	escreve_LCD_Flash(msg_retire_o_copo);
	
	if(!tst_bit(PINC,3))
	{
		cmd_LCD(0x80,0); //inicializa cursor na primeira posição a esquerda - 1a linha
		escreve_LCD_Flash(msg_sem_copo);
		_delay_ms(500);
		cmd_LCD(0x80,0); //inicializa cursor na primeira posição a esquerda - 1a linha
		escreve_LCD_Flash(msg_fim);
		_delay_ms(500);
		estado=14;
		tempo = tempo_tamanho*100;
	}
}

void reinicializando() 
   {  clr_bit(PORTB,valvula_leite);  
	  clr_bit(PORTB,valvula_cafe); 
	  clr_bit(PORTB,valvula_capuccino);
	  clr_bit(PORTB,valvula_acucar);
	  cmd_LCD(0x80,0); //inicializa cursor na primeira posição a esquerda - 1a linha
      escreve_LCD_Flash(msg_reiniciando);
 	  if(!tempo)
	       { estado=1; }	
	}

void configura_temporizacao() {
	
	/* TCCR0A  Registrador de controle A do TC0
	COM0A1 COM0A0 COM0B1 COM0B0  -     -     WGM01 WGM00
	 7        6     5      4     3     2       1     0

	 COM0A1 COM0A0 controlam o comportamento do pino 0C0A (modos normal, CTC, pwm rapido)
	   0      0  - pino 0C0A desconectado
	   0      1  - mudanca de estado na igualdade
	   1      0  - aterrado na igualdade
	   1      1  - Ativo  na igualdade

	   COM0B1 COM0B0  controlam o comportamento do pino 0C0B
	   0      0  - pino 0C0B desconectado
	   0      1  - mudanca de estado na igualdade
	   1      0  - aterrado na igualdade
	   1      1  - Ativo  na igualdade

	   WGM02 WGM01 WGM00 bits do modo de controle, fonte do valor maximo e forma de onda
	   0     0     0  - normal     TOP em FF
	   0     0     1  - pwm fase corrigida top em FF
	   0     1     0  - CTC        TOP em 0CR0A
	   0     1     1  - pwm rapido  TOP em FF
	   1     0     0  - 
	   1     0     1  - pwm fase corrigida top em 0CR0A
	   1     1     0   -
	   1     1     1  - pwm rapido TOP em 0CR0A
	*/
	
	TCCR0B = (1<<CS02) | (1<<CS00);		//TC0 com prescaler de 1024, a 16 MHz gera uma interrupção a cada 16,384 ms
	/* TCCR0B  Registrador de controle B do TC0
	F0C0A  FOC0B   -    -   WGM02  CS02  CS01  CS00
	7        6     5    4     3      2    1      0

	CS02  CS01  CS00  bits de selecao do prescaler
	   0     0     0  - sem fonte de clock tc0 parado
	   0     0     1  - prescaler =1
	   0     1     0  - prescaler = 8
	   0     1     1  - prescaler = 64
	   1     0     0  - prescaler = 256
	   1     0     1  - prescaler = 1024
	   1     1     0  - clock externo pino T0 (pd4) contagem borda descida
	   1     1     1  - clock externo pino T0 (pd4) contagem borda subida     
	*/

	TIMSK0 = 1<<TOIE0;					//habilita a interrupção do TC0
	/* TIMSK0 Interruptor de mascara do contador TC0
	- - - - - 0CIE0B 0CIE0A TOIE0
	7 6 5 4 3   2      1      0
	0CIE0B ativa a interrupção na igualdade de comparação 0CR0B
	0CIE0A ativa a interrupção na igualdade de comparação 0CR0A
	TOIE0  ativa a interrupção de estouro em TOP=FF

	*/
  TCNT0=100;
	
	sei();								//habilita interrupções globais

   conta=100;
	
}