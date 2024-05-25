# Integrantes:
- RM553842 Gustavo Gouvêa Soares
- RM553945 Henrique Rafael Gomes de Souza
- RM554223 Pedro Henrique Mello Silva Alves

# Materiais:
- 1 led verde
- 1 led vermelho
- 1 led amarelo
- 1 led rgb
- 6 resistores 300 ohms
- 1 buzzer
- 1 Placa Arduino

# Dependências:
- Biblioteca ArduinoJson para sua IDE de Arduino

# Instruções:
- Gerar uma api local através do projeto em python:
https://github.com/OlaMeusAmigues/Challenge-Python-2023-2024.git
- Rodar o código fonte no seu Arduino
- Abrir o Command Prompt e inserir:
npm install -g --unsafe-perm node-red
- No mesmo terminal, rodar o servidor pelo comando:
node-red
- Abrir o servidor no endereço: http://localhost:1880
- Importar o node_red.json para criar os nós necessários para o servidor
- Inserir no nó Serial out a porta do seu Arduino
- No Websock-Client da HiveMQ, se registrar no tópico:
grupo4/paciente/dados_vitais
- Iniciar as funcionalidades do servidor clicando no botão do nó Injetar
- Atualizar o estado do paciente através do menu do código em python

# Funcionalidades:
Através da leitura da API, o servidor node-red filtra as informações referentes a dados vitais do paciente, enviando as últimas leituras a cada 4 segundos tanto para o Websock-Client da HiveMQ como para o Arduino.
Para o Arduino, será dada a função de monitor de dados vitais dentro de um hospital.Em que:
- O led rgb possui 3 estados: azul(esperando informações), verde(sem discrepância de dados vitais) e vermelho(discrepância de dados vitais)
- O buzzer tocando por 0.5 segundos indica nenhuma discrepância e por 1 segundo indica uma ou mais discrepâncias
- O led verde ligado indica valores perigosos de pressão
- O led vermelho ligado indica valores perigosos de temperatura
- O led amarelo ligado indica valores perigosos de batimentos cardíacos
