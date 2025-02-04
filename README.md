# Trabalho-FInal-PROG

Registro de uso DIARIO

controlar entrada e saida
consumo do estoque
prever reposicao com base no padrao de uso


I. cadastro de insumo
- nome
- categoria
 - semente\fertilizante..
-unidade de medida/quantidade (kg, litro, un)
-quantidade inicial de cada insumo(cadastrarei x insumos novos)

II. exibir tudo que foi cadastrado e organizados

III. adicionar novos insumos com a quantidade recebida e atualizar automaticamente

IV. Atualizar estoque quando algum insumo for usado detalhando quantidade que foi usada e a data do uso

V. Registro de
- data do registro (como vai ser diario entao sempre vai mudar)
- nome dele
- quantidade adicionada ou usada
- quantidade total apos a movimentacao

____________________________________________________________________________
A lógica que usamos foi a de criar uma função log para que todo e qualquer registro seja feito e guardado, tal função é ligada a todas as outras ja que a mesma possui o objetivo de armazenar logs em um arquivo.

A funcao de tempo que usamos foi através de pesquisas conseguimos formula-la
[base func dataTime](https://stackoverflow.com/questions/1442116/how-to-get-the-date-and-time-values-in-a-c-program)

Optamos por usarmos apenas um arquivo que vai ter todo o objeto em si, logo não usamos as funções de alocação dinâmica (malloc e calloc)

Em certa parte utilizamos a função de strcpy que vai copiar o conteúdo antes de ser edistado ou excluído e assim podemos utilizar essa opção posteriormente para podermos mostrar para o usuário caso ele queira saber como estava antes da edição, porem não foi pertinente implementar isso.

Trabalho Final de prog I
-Felipe Muraro Silva Vilela
-Sophia Camargo Tercette
