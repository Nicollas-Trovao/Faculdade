# 📚 Portfolio em C

Repositório com programas e projetos desenvolvidos em C durante o curso de Faculdade.

## 📂 Projetos

### 1. **Validador de CPF** (`cpf.c`)
Programa que valida números de CPF brasileiros.

#### Funcionalidades:
- ✅ Extrai apenas números do input (aceita CPF com ou sem formatação)
- ✅ Valida comprimento (11 dígitos)
- ✅ Detecta CPFs inválidos (todos os dígitos iguais)
- ✅ Calcula e verifica os dois dígitos verificadores
- ✅ Aguarda confirmação antes de sair

#### Como usar:
```bash
gcc cpf.c -o cpf
./cpf
```

Digite o CPF no formato:
- `123.456.789-00` (com formatação)
- `12345678900` (sem formatação)

---

### 2. **Jogo de Adivinhação** (`adivinhacao.c`)
Jogo interativo onde o computador pensa em um número e você tenta adivinhar.

#### Funcionalidades:
- 🎮 O programa gera um número aleatório
- 🔢 Você tenta adivinhar o número
- 💡 Recebe dicas (maior ou menor)
- 📊 Mostra quantas tentativas foram necessárias
- 🎯 Opção de jogar novamente

#### Como usar:
```bash
gcc adivinhacao.c -o adivinhacao
./adivinhacao
```

Siga as instruções na tela para jogar!

---

## 🛠️ Requisitos

- **Compilador GCC** (ou qualquer compilador C compatível)
- **Sistema Operacional:** Windows, Linux ou macOS

### Instalação do GCC:
- **Windows:** [MinGW](https://www.mingw-w64.org/)
- **Linux:** `sudo apt-get install gcc` (Debian/Ubuntu)
- **macOS:** `xcode-select --install`

---

## 📝 Estrutura do Projeto

```
portfolio-c/
├── cpf.c                    # Validador de CPF
├── adivinhacao.c            # Jogo de Adivinhação
├── README.md                # Este arquivo
└── .vscode/                 # Configurações do VS Code
```

---

## 🚀 Como Compilar

### Opção 1: Compilar diretamente
```bash
gcc cpf.c -o cpf
gcc adivinhacao.c -o adivinhacao
```

### Opção 2: Usar VS Code (com extensão C/C++)
- Abra o arquivo `.c`
- Pressione `Ctrl+Shift+B` (ou use a tarefa de compilação)

---

## 📖 Aprendizados

Estes projetos cobrem conceitos fundamentais de C:
- 🔹 Entrada/Saída (scanf, printf)
- 🔹 Estruturas de Controle (if, while, for)
- 🔹 Arrays e Strings
- 🔹 Funções
- 🔹 Validação de Dados
- 🔹 Geração de Números Aleatórios

---

## 👨‍💻 Autor

**Nicollas Trovão**  
📧 nictrova200o@gmail.com  
🔗 [GitHub](https://github.com/Nicollas-Trovao)

---

## 📄 Licença

Este projeto é educacional e de código aberto. Sinta-se livre para usar, modificar e distribuir.

---

## 🤝 Contribuições

Sugestões de melhorias são bem-vindas! Abra uma *issue* ou faça um *pull request*.

---

**Última atualização:** 2026-08-17
