# OBI Soluções Colaborativas
Este repositório público foi criado para que os estudantes do 1º semestre dos cursos de tecnologia que irão participar da Olimpíada Brasileira de Informática (OBI) possam compartilhar suas soluções para as questões de anos anteriores. O objetivo é incentivar o estudo de lógica, algoritmos e a prática colaborativa.

---

## Estrutura do Repositório

Para masnter a organização, tente seguir esta estrutura de pastas:

```text
/
└── 2025
    └── Nível (Ex: Nível_Universitario)
       └── Fase (Ex: Fase_1, Fase_2)
          └── Nome_da_Questao
             ├── solucao_wictor.py
             └── solucao_vicente.c   
             
```

---

## Como contribuir?

Antes de iniciar qualquer comando, vá até a página principal desde repositório no GitHub e clique no botão **Fork** (localizado no canto superior direito) para gerar uma cópia do projeto na sua conta pessoal.

   <img width="1366" height="768" alt="fork copia" src="https://github.com/user-attachments/assets/b046d6cb-51f7-48de-b327-b14bd71a64ca" />

   <img width="1366" height="768" alt="fork copia 2" src="https://github.com/user-attachments/assets/604779ff-22de-4b19-8ad4-52178caf672b" />
   
### Opção A: Utilizando o Git Bash / Terminal

#### 1. Clonar e Acessar o Repositório
Abra o seu git bash ou terminal na pasta onde costuma guardar seus dódigos e execute:
```bash
git clone https://github.com/SEU-USUARIO/nome-do-repositorio.git
cd nome-do-repositorio
```
**Importante:** Você **precisa** entrar na pasta do projeto com o comando `cd` antes de rodar qualquer outro comando do Git!

#### 2. Criar uma Branch Limpa
Garanta que você está na ramificação principal (`main`) e crie uma nova branch exclusiva para a questão que irá resolver:
```bash
git switch main
git switch -c solucao-nome-da-questao
```
*(Se o seu Git for mais antigo, você também pode usar: `git checkout -b solucao-nome-da-questao`)*

#### 3. Adicionar seu Código
Navegue pelo gerenciador de arquivos e salve o arquivo com o seu código escrito na linguaguem escolhida (`.c`, `.py`, `.cpp`, etc.) dentro da pasta correspondente da questão.
**Nota:** Nunca incialize o Git novamente (`git init`) dentro das subpastas para não quebrar o histórico do repositório.

#### 4. Enviar as Alterações
Retorne à raiz do projeto no seu terminal, prepare o salvamento e envie os dados para o seu GitHub:
```bash
git add .
git commit -m "Solução: Nome da Questão (Ano - Fase)"
git push -u origin solucao-nome-da-questao
```

---

### Opção B: Utilizando o GitHub Desktop

#### 1. Clonar o Repositório
1. Na página do **seu fork** no navegador, clique no botão verde **Code** e selecione a opção **Open with GitHub Desktop**.
2. O aplicativo será aberto automaticamente. Confirme o diretório local no seu computador e clique em **Clone**.

#### 2. Criar uma Nova Branch
1. Na barra superior do aplicativo, clique no botão **Current Branch** (que por padrão inicia em `main`).
2. Clique no botão **New Branch**.
3. Batize a branch com o nome da questão (ex: `solução-nome-da-questao`) e clique em **Create Branch**.
4. Caso surja uma janela perguntando se deseja basear suas alterações na branch `main`, confirme que **sim**.

#### 3. Adicionar seu Código
1. Abra as pastas do seu computador e vá até o local onde o repositório foi clonado.
2. Siga a estrutura de pastas até a questão desejada (`Ano/Nivel/Fase/Nome_da_Questao`) e cole o arquivo da sua solução ali dentro.

#### 4. Fazer o Commit e Push
1. Ao reabrir o GitHub Desktop, os arquivos criados serão listados na aba lateral esquerda (*Chanves*)
2. No canto inferior esquerdo, escreva o título da sua alteração no campo *Summary* (ex: `Solução: Nome da Questão`).
3. Clique no botão azul **Commit to solucao-nome-da-questao**.
4. Na barra superior do aplicativo, clique no botão **Publish branch** para carregar os dados para o GitHub.

---

## Passo Final: Abrindo o Pull Request (Para Ambos)

1. Acesse a página do **seu fork** no site do GitHub.
2. Um quadro informativo amarelo destacará que você realizou um envio recente. Clique no botão verde **"Compare & pull request"**.
   * *Caso o aviso não esteja visível:* Clique na aba **Pull Request** e selecione o link **"compare across forks"**.
  
   <img width="1366" height="768" alt="pull request 1" src="https://github.com/user-attachments/assets/d8bab572-cc93-4c40-b528-cd2d28951d5c" />
     
3. Certifique-se de configurar os campos de comparação exatamente com esta ordem:
   * **base repository:** repositório original principal
| **base:** `main`
   * **head repository:** seu-usuario/nome-do-repositorio
| **compare:** `solução-nome-da-questao`
4. Insira um título descritivo para a sua contribuição (ex: `Solução: Nome da Questão (Ano - Fase)`) e finalize clicando em **Create pull request**.

   <img width="1366" height="768" alt="pull request 2" src="https://github.com/user-attachments/assets/e9a77755-90a6-47b9-b64b-cf87088d0920" />

---

## Regras de Convivência
  * Respeite o código do colega. Comentários construtios são sempre bem-vindos!
  * Procure seguir as boas práticas: idente seu código, use nomes de variáveis que façam sentido com o contexto e sempre adicione comentários explicando a lógica que você utilizou para chegar ao resultado. Isso ajuda muito quem está tentando aprender a sua solução!
