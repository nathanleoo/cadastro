
# 🧑 Cadastro de Pessoas em C

Um mini sistema em C que permite **cadastrar, listar, buscar, editar e excluir pessoas**, com **armazenamento persistente em arquivo**. Ideal para estudos de programação estruturada com structs, arquivos e vetores.

---

## 📋 Funcionalidades

✅ Cadastrar nome e idade de pessoas  
✅ Listar todos os cadastros  
✅ Buscar pessoas pelo nome  
✅ Editar cadastros existentes  
✅ Excluir cadastros  
✅ Dados persistentes em arquivo `.txt`  
✅ Interface de menu interativa no terminal

---

## 💡 Tecnologias

- Linguagem C (C99)
- Terminal (CLI)
- Manipulação de arquivos com `fopen`, `fprintf`, `fscanf`

---

## ▶️ Como executar

### 1. Clone o repositório
```bash
git clone https://github.com/seu-usuario/nome-do-repositorio.git
cd nome-do-repositorio
```

### 2. Compile o código

Usando `gcc` (Linux/Mac/WSL):
```bash
gcc cadastro.c -o cadastro
```

No Windows (MinGW):
```bash
gcc cadastro.c -o cadastro.exe
```

### 3. Execute

Linux/macOS:
```bash
./cadastro
```

Windows:
```bash
cadastro.exe
```

---

## 💾 Exemplo de uso

```bash
--- MENU ---
1. Cadastrar pessoa
2. Listar cadastros
3. Buscar por nome
4. Editar cadastro
5. Excluir cadastro
6. Sair
Escolha uma opção: 1

Digite o nome: João Silva
Digite a idade: 25
Pessoa cadastrada com sucesso!
```

---

## 📂 Arquivo gerado

O programa gera automaticamente um arquivo `cadastros.txt` com os dados salvos, assim:

```
João Silva
25
Maria Oliveira
32
```

---

## 📈 Possíveis melhorias

- Ordenação por nome ou idade  
- Validação de campos (ex: idade mínima)  
- Cadastro com CPF ou ID único  
- Exportação para CSV  
- Interface gráfica com C/GTK ou integração com banco de dados

---

## 🧑‍🏫 Projeto acadêmico

Este projeto foi desenvolvido como parte das atividades da disciplina de Fundamentos de Programação da Faculdade Católica de Santa Catarina.

---

## 📄 Licença

Este projeto está sob a licença MIT. Consulte o arquivo `LICENSE` para mais informações.

---

## 🤝 Contribuições

Contribuições são bem-vindas!  
Abra uma issue ou envie um pull request.

---

## ✍️ Autor

**Nathan Leonardo**  
[LinkedIn](www.linkedin.com/in/nathan-leonardo-370b85328)
