#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[101];
    char dob[11];
    float score1, score2, score3, totalScore;
} Candidate;

int main() {
    int n, i, maxIndex = 0;
    printf("Nhap so luong thi sinh: ");
    scanf("%d", &n);
    Candidate candidates[n];

    for (i = 0; i < n; i++) {
        candidates[i].id = i + 1;
        getchar();
        printf("Nhap ten thi sinhh %d: ", i + 1);
        fgets(candidates[i].name, sizeof(candidates[i].name), stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = '\0';

        printf("Nhap ngay sinh thi sinh %d: ", i + 1);
        fgets(candidates[i].dob, sizeof(candidates[i].dob), stdin);
        candidates[i].dob[strcspn(candidates[i].dob, "\n")] = '\0';

        printf("Nhap diem 3 mon cua thi sinh %d: ", i + 1);
        scanf("%f %f %f", &candidates[i].score1, &candidates[i].score2, &candidates[i].score3);

        candidates[i].totalScore = candidates[i].score1 + candidates[i].score2 + candidates[i].score3;
    }

    for (i = 1; i < n; i++) {
        if (candidates[i].totalScore > candidates[maxIndex].totalScore ||
            (candidates[i].totalScore == candidates[maxIndex].totalScore && candidates[i].id < candidates[maxIndex].id)) {
            maxIndex = i;
        }
    }

    printf("%d %s %s %.1f\n", candidates[maxIndex].id, candidates[maxIndex].name, candidates[maxIndex].dob, candidates[maxIndex].totalScore);

    return 0;
}
