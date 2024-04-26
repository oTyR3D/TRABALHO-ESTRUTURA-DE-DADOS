#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float X;
    float Y;
} Ponto;

float AreaTriangulo(Ponto A, Ponto B, Ponto C);

int main() {
    FILE *arquivo;

    int nVertices;
    Ponto vertices[30];

    arquivo = fopen("poligono.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fscanf(arquivo, "%d", &nVertices);

    for (int i = 0; i < nVertices; i++) {
        fscanf(arquivo, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    fclose(arquivo);

    float area = 0;
    for (int i = 0; i < nVertices - 2; i++) {
        area += AreaTriangulo(vertices[0], vertices[i + 1], vertices[i + 2]);
    }
        area=area*-1;
    printf("A área do polígono é %.2f\n", area);

    return 0;
}

float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    return 0.5 * (A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y));
}