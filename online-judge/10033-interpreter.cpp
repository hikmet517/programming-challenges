#include <iostream>
#include <array>


using namespace std;


std::array<int, 10> registers;
std::array<int, 1000> memory;


int executed = 0;  // total instructions executed
int pc = 0;  // program counter


void reset()
{
    registers = {0};
    memory = {0};
    executed = 0;
    pc = 0;
}

// 100
void halt()
{
    pc = -1;
    executed++;
}

// 2dn
void setRegister(int d, int n)
{
    registers[d] = n;
    executed++;
    pc++;
}

// 3dn
void addToRegister(int d, int n)
{
    registers[d] += n;
    registers[d] %= 1000;
    executed++;
    pc++;
}

// 4dn
void multiplyRegister(int d, int n)
{
    registers[d] *= n;
    registers[d] %= 1000;
    executed++;
    pc++;
}

// 5ds
void setRegisterFromRegister(int d, int s)
{
    registers[d] = registers[s];
    executed++;
    pc++;
}

// 6ds
void addRegisterFromRegister(int d, int s)
{
    registers[d] += registers[s];
    registers[d] %= 1000;
    executed++;
    pc++;
}

// 7ds
void multiplyRegisterFromRegister(int d, int s)
{
    registers[d] *= registers[s];
    registers[d] %= 1000;
    executed++;
    pc++;
}

// 8da
void setRegisterFromMemory(int d, int a)
{
    registers[d] = memory[registers[a]];
    executed++;
    pc++;
}

// 9sa
void setMemoryFromRegister(int s, int a)
{
    memory[registers[a]] = registers[s];
    executed++;
    pc++;
}

// 0ds
void gotoFromRegister(int d, int s)
{
    if (registers[s] != 0) {
        pc = registers[d];
    }
    else {
        pc++;
    }
    executed++;
}

void print()
{
    cout << "regs: ";
    for (int elem : registers)
        cout << elem << " ";
    cout << " pc: " << pc << "\n";
}


void run(int instruction)
{
    int cmd = (instruction / 100) % 10;
    int arg1 = (instruction / 10) % 10;
    int arg2 = instruction % 10;
    switch (cmd) {
    case 1:
        halt();
        break;
    case 2:
        setRegister(arg1, arg2);
        break;
    case 3:
        addToRegister(arg1, arg2);
        break;
    case 4:
        multiplyRegister(arg1, arg2);
        break;
    case 5:
        setRegisterFromRegister(arg1, arg2);
        break;
    case 6:
        addRegisterFromRegister(arg1, arg2);
        break;
    case 7:
        multiplyRegisterFromRegister(arg1, arg2);
        break;
    case 8:
        setRegisterFromMemory(arg1, arg2);
        break;
    case 9:
        setMemoryFromRegister(arg1, arg2);
        break;
    case 0:
        gotoFromRegister(arg1, arg2);
        break;
    default:
        break;
    }
}


int main()
{
    string line;
    getline(cin, line);
    int count = stoi(line);
    getline(cin, line); // consume blank line
    for (int i = 0; i < count; i++) {
        reset();

        // load content into memory
        int c = 0;
        line = "";
        while (getline(cin, line)) {
            if (line == "") {
                break;
            }

            int content = stoi(line);
            memory[c++] = content;
            // cout << "content: " << content << endl;
        }

        if (c != 0) {
            while (pc != -1) {
                run(memory[pc]);
                // print();
            }
            cout << executed << '\n';
        }
        if (i != count - 1)
            cout << '\n';
    }
    return 0;
}
