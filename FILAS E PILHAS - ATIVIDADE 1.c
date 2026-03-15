/******************************************************************************

1. Descrever (em portugues ou como preferir) as funções de inserção e remoção da fila;
2. Pesquisar problema da "Fila cheia vazia" . Descreva o que é. Como resolver?


3. Descrever em portugues as operações PUSH e POP (PILHA), indicar os erros que podem acontecer.
4. O que é: Stack overflow e stack underflow?


*******************************************************************************/
1. INSERCAO  FILA - 
A função de inserção deve receber como parâmetro o dado a ser inserido e a posição
que deve ser inserido, que no caso é a acima da útima ocupada, so caso do vetor, a indice
da posição


PREMEIRO VERIFICA SE ESTÁ VAZIA - SE VAZIA INSERI 1 ATUALIZA O COMEÇO E FIM
SE NÃO É O PRIMEIRO SÓ ALTERA O ÚLTIMO
SE REMOVE UM DO COMEÇO ATUALIZA O ÚLTIMO

1 2 3 preenchidos
0 1 2  indice
inserindo
0 1 2 3 vai inserir no indice 3, ou seja, posição de inserção = número preenchidos


REMOÇÃO FILA - vai remover o primeiro do vetor 

