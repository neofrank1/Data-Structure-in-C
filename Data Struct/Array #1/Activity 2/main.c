/*
Filename: UyActivity2.c
Description: Vote Count for Politics
Programmer: Neo Frank D. Uy
Date: Sept 10, 2020
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char politician[4] = {'A','B','C','D'};
    int i,j;
    int total_votes = 0;
    int all_total = 0;
    int candidate[5][4] = {{192,48,206,37},{147,90,312,21},{186,12,121,38},{114,21,108,39},{267,13,382,29}};
    float winner_1,winner_2;
    float percentage;
    float passing[4];

    printf("Precinct\tCandidate A\tCandidate B\tCandidate C\tCandidate D\n");

    for(i=0;i<5;i++) // Display the Votes
    {
        printf("%d\t\t",i+1);
        for(j=0;j<4;j++)
        {
            printf("%d\t\t",candidate[i][j]);
        }
        printf("\n");
    }

    printf("Total: \t\t");
    all_total = 0;

    for(i=0;i<4;i++) // Table For the Results of Total per Candidates Votes //
    {
        total_votes = 0;
        for(j=0;j<5;j++)
        {
            total_votes += candidate[j][i];
            all_total += candidate[j][i];
        }
        printf("%d\t\t",total_votes);
    }
    printf("Total Of All Votes: %d\n",all_total);
    printf("Percentage:\t");

    for(i=0;i<4;i++) // Computes the percentage of the votes per candidates //
    {
        total_votes = 0;
        for(j=0;j<5;j++)
        {
            total_votes += candidate[j][i];
            percentage = ((float)total_votes / all_total) * 100;

        }
        printf("%.2lf\t\t",percentage);
        passing[i] = percentage;
    }

 /*   for (i=0;i<4;i++) // If the Candidate C has a 408 Votes //
    {
        if (passing[i] >= 50)
        {
            printf("\nThe Winner Is Candidate %c",politician[i]);
            break;
        }
    }
*/

    winner_1 = passing[0]; // If the Candidate C has a 108 Votes //
    winner_2 = 0;

    for (i=0;i<4;i++)
    {
        if (passing[i] > winner_1)
        {
            winner_1 = passing[i]; // Storing the First Largest Percentage of the Votes //
            passing[i] = 0;
        }
    }

    winner_2 = passing[1];

    for(i=0;i<4;i++)
    {
        if (passing[i] != winner_1)
        {
            if (passing[i] > winner_2)
            {
                winner_2 = passing[i]; // Storing the Seconds Largest Percentage of the Votes //
                passing[i] = 0;
            }
        }
    }

    for(i=0;i<4;i++) // Display the Winners of the Election //
    {

        if (passing[i] == 0)
        {
            printf("\nThe Winners Candidate %c",politician[i]);
        }
    }


    return 0;
}
// Copyright Neo Frank D. Uy 2020 //
