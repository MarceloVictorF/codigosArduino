// Marcelo Victor Ferreira Barbosa
// Código para uma ESP32 mestre se comunicar via protocolo CAN com outras ESP32
// CAN_H1 e CAN_H2 são pinos usados para gerar tensões de 1.65v e 3.3v sobre o CAN_H através do divisor de tensão da camada física.
int CAN_H1 = 4;
int CAN_H2 = 5;

// CAN_L1 e CAN_L2 são pinos usados para gerar tensões de 0v e 1.65v sobre o CAN_L através do divisor de tensão da camada física.
int CAN_L1 = 0;
int CAN_L2 = 2;

// E1 e E2 são pinos usados para determinar a menssagem que será enviada.
int E1 = 12;
int E2 = 14;

// Sincroniza é o pino usado para sincronização de envio e recepção da menssagem.
int Sincroniza = 26;

// Incializa o estado da menssagem a ser enviada como 00.
int estadoE1 = 0;
int estadoE2 = 0;

// Incializa o estado do pino de sincronização em 0.
int estadoSincroniza = 0;

void setup() {
  // Inicializa o terminal serial.
  Serial.begin(9600);

  // Indica que os pinos CAN_H1 e CAN_H2 serão usados como saída.
  pinMode(CAN_H1, OUTPUT);
  pinMode(CAN_H2, OUTPUT);

  // Indica que os pinos CAN_L1 e CAN_L2 serão usados como saída.
  pinMode(CAN_L1, OUTPUT);
  pinMode(CAN_L2, OUTPUT);

  // Indica que os pinos E1 e E2 serão usados como entrada.
  pinMode(E1, INPUT);
  pinMode(E2, INPUT);

  // Indica que o pino Sincroniza será usado como entrada.
  pinMode(Sincroniza, INPUT);
}

void loop() {
  // Lê o valor do estado de sincronização, caso o botão seja apertado o estadoSincroniza guardará valor alto.
  estadoSincroniza = digitalRead(Sincroniza);
  // Se o botão de sincronização for pressionado, ou seja, estadoSincroniza for alto.
  if(estadoSincroniza == HIGH){
    Serial.println("O botão de sincronização foi pressionado.");
    // Lê os estados das portas do dip switch que pode ser 00, 01, 10 e 11. Para cada estado uma menssagem diferente será enviada. 
    estadoE1 = digitalRead(E1);
    estadoE2 = digitalRead(E2);
    Serial.print("E1: ");
    Serial.print(estadoE1);
    Serial.print(". E2: ");
    Serial.print(estadoE2);
    Serial.println(".");
    if((estadoE1 == LOW) && (estadoE2 == LOW)){
      Serial.println("Enviando MSG1.");
      // Start of Frame(SOF) tem que ser dominante.
      bitZero();
      // Identifier(ID == 00110000001)
      // Function code.
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      // ID:
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      // Remote Transmisson Request(RTR), como é dataframe deve ser dominante, ou seja, zero.
      //bitZero();
      // Data Field: MSG1
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();

      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitUm();

      bitZero();
      bitUm();
      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();

      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitUm();

      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      // End Of Frame(EOF) tem que ser recessivo.
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      Serial.println("MSG1 enviada.");
    }
    if((estadoE1 == HIGH) && (estadoE2 == LOW)){
      Serial.println("Enviando MSG2.");
      // Start of Frame(SOF) tem que ser dominante.
      bitZero();
      // Identifier(ID == 00110000010)
      // Function code.
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      // ID:
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      bitZero();
      // Remote Transmisson Request(RTR), como é dataframe deve ser dominante, ou seja, zero.
      //bitZero();
      // Data Field: MSG2
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();

      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitUm();

      bitZero();
      bitUm();
      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();

      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitUm();

      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitZero();
      // End Of Frame(EOF) tem que ser recessivo.
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      Serial.println("MSG2 enviada.");
    }
    if((estadoE1 == LOW) && (estadoE2 == HIGH)){
      Serial.println("Enviando MSG3.");
      // Start of Frame(SOF) tem que ser dominante.
      bitZero();
      // Identifier(ID == 00110000001)
      // Function code.
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      // ID:
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      // Remote Transmisson Request(RTR), como é dataframe deve ser dominante, ou seja, zero.
      //bitZero();
      // Data Field: MSG3
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitUm();
      bitZero();
      bitUm();
      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitUm();

      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      // End Of Frame(EOF) tem que ser recessivo.
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      Serial.println("MSG3 enviada.");
    }
    if((estadoE1 == HIGH) && (estadoE2 == HIGH)){
      Serial.println("Enviando MSG4.");
      // Start of Frame(SOF) tem que ser dominante.
      bitZero();
      // Identifier(ID == 00110000001)
      // Function code.
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      // ID:
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      bitZero();
      // Remote Transmisson Request(RTR), como é dataframe deve ser dominante, ou seja, zero.
      //bitZero();
      // Data Field: MSG4
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();
      bitZero();

      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitUm();

      bitZero();
      bitUm();
      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitUm();
      bitUm();

      bitZero();
      bitUm();
      bitZero();
      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitUm();

      bitZero();
      bitZero();
      bitUm();
      bitUm();
      bitZero();
      bitUm();
      bitZero();
      bitZero();
      // End Of Frame(EOF) tem que ser recessivo.
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      bitUm();
      Serial.println("MSG4 enviada.");
    }
  }
  else{
    bitUm();
  }
}

void bitUm() {
  digitalWrite(CAN_H1, HIGH);
  digitalWrite(CAN_H2, LOW);
  digitalWrite(CAN_L1, HIGH);
  digitalWrite(CAN_L2, LOW);
  delay(1800);
  digitalWrite(CAN_H1, LOW);
  digitalWrite(CAN_H2, LOW);
  digitalWrite(CAN_L1, LOW);
  digitalWrite(CAN_L2, LOW);
  delay(200);
}
void bitZero() {
  digitalWrite(CAN_H1, HIGH);
  digitalWrite(CAN_H2, HIGH);
  digitalWrite(CAN_L1, LOW);
  digitalWrite(CAN_L2, LOW);
  delay(1800);
  digitalWrite(CAN_H1, LOW);
  digitalWrite(CAN_H2, LOW);
  digitalWrite(CAN_L1, LOW);
  digitalWrite(CAN_L2, LOW);
  delay(200);
}
