#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int parentesi_valide(const char* s) {
    char stack[MAX_LEN];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            // Push sullo stack
            if (top >= MAX_LEN - 1) return 0; // stack overflow
            stack[++top] = c;
        } else {
            // Stack vuoto → parentesi chiusa senza aperta
            if (top < 0) return 0;

            // Controllo corrispondenza
            char open = stack[top--]; // pop 
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                return 0;
            }
        }
    }

    // Stack deve essere vuoto alla fine
    return top == -1;
}

int main() {
    const char* test_cases[] = {
        "()",         // valido
        "()[]{}",     // valido
        "(]",         // non valido
        "([)]",       // non valido
        "{[]}",       // valido
        "(",          // non valido
        "",           // valido (nessuna parentesi = valido)
        "([]{})",     // valido
        "[(])",       // non valido
        NULL          // terminatore
    };

    for (int i = 0; test_cases[i] != NULL; i++) {
        const char* s = test_cases[i];
        printf("Test \"%s\" → %s\n", s, parentesi_valide(s) ? "valido" : "non valido");
    }

    return 0;
}
