/*
Conversation opened. 3 messages. All messages read.

Skip to content
Using Gmail with screen readers
Search



Click here to enable desktop notifications for Gmail.   Learn more  Hide
Gmail
COMPOSE
Labels
Inbox (4)
Starred
Important
Sent Mail
Drafts (21)
Circles
Notes
Personal
Travel
More
Hangouts



  More
2 of 281

Expand all Print all In new window
APC Sol 2, 3
Inbox
x

Anirudh Khanna		AttachmentsJul 15 (5 days ago)
PFA

Anirudh Khanna		Attachments12:10 PM (22 hours ago)
PFA

Anirudh Khanna <anirudhkhanna.cse@gmail.com>
Attachments11:06 PM (11 hours ago)

to me

Attachments area

Click here to Reply or Forward
2.12 GB (14%) of 15 GB used
Manage
Terms - Privacy
Last account activity: 3 hours ago
Details
Anirudh Khanna's profile photo
Anirudh Khanna
Add to circles

Show details
*/
#include <stdio.h>
#include <string.h>


int is_anagram(char *s1, char *s2)
{
    int A1[256]={0}, A2[256]={0};

    int i, j;
    for(i=0; s1[i]!='\0'; i++)
        A1[s1[i]]++;

    for(i=0; s2[i]!='\0'; i++)
        A2[s2[i]]++;

    for(i=0; i<256; i++)
    {
        if(A1[i]!=A2[i])
            return 0;
    }

    return 1;
}

int main()
{
    int N;
    scanf("%d", &N);
    char s[N][100];
    int i, j;

    for(i=0; i<N; i++)
        scanf("%s", s[i]);

    for(i=0; i<N; i++)
        printf("%s ", s[i]);

    printf("\n\nANAGRAMS:\n");

    for(i=0; i<N; i++)
    {
        puts(s[i]);
        for(j=i+1; j<N; j++)
        {
            if(s[j][0]!=0 && is_anagram(s[i], s[j]))
            {
                puts(s[j]);
                s[j][0]=0;
            }
        }

      //printf("\n");
    }

    return 0;
}
