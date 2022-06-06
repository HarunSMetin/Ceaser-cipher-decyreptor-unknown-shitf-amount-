#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv)
{
    char inputRef[100];
    char inputCrypted[100];
    char output[100];

    int i;
    for(i=0; i<argc; ++i)
    {
        if((*argv[i] == '-') && (*(argv[i]+1)== 'r')){
            i+=1;
            strncpy(inputRef, argv[i],sizeof(inputRef));
        }else if((*argv[i] == '-') && (*(argv[i]+1) == 'c')){
            i+=1;
            strncpy(inputCrypted, argv[i],sizeof(inputCrypted));
        }else if((*argv[i] == '-') && (*(argv[i]+1) == 'p')){
             i+=1;
            strncpy(output, argv[i],sizeof(output));
        }
    }
    printf("InputRef File : %s\n", inputRef);
    printf("InputCrypted File : %s\n", inputCrypted);
    printf("Output File : %s\n\n", output);


    int timesRef[26];
    int totalCharNumRef=0; //just Alphabetic Chars
    char alph[]="abcdefghijklmnopqrstuvwxyz";
    int timesCrypted[26];
    int totalCharNumCrypted=0; //just Alphabetic Chars

    for (int i = 0; i < 26; ++i) {timesRef[i]=0; timesCrypted[i]=0;}

////////////////////////////////////////////////////
    FILE *filePointer;
    char ch;
    filePointer = fopen(inputRef, "r");
    if (filePointer == NULL) printf("%s is not available \n",inputRef);
    else
    {
        while ((ch = fgetc(filePointer)) != EOF)
        {
            for (int i = 0; i < 26; ++i) if(tolower(ch) == alph[i]) timesRef[i]++;
        }
        for (int i = 0; i < 26; ++i) totalCharNumRef+=timesRef[i];
    }
    fclose(filePointer);
    ///////////////////////////////
    char ch2;
    FILE *filePointer2;
    filePointer2 = fopen(inputCrypted, "r");
    if (filePointer2 == NULL)printf("%s is not available \n",inputCrypted);
    else
    {
        while ((ch2 = fgetc(filePointer2)) != EOF)
        {
            for (int i = 0; i < 26; ++i) if(tolower(ch2) == alph[i]) timesCrypted[i]++;
        }
        for (int i = 0; i < 26; ++i) totalCharNumCrypted+=timesCrypted[i];
    }
    fclose(filePointer2);
////////////////////////////////////////////////////
    int maxRef,minRef,minIndexRef,maxIndexRef;

    minRef=timesRef[0];
    maxRef=timesRef[0];

    for(int i=1;i<26;i++)
    {
        if(minRef > timesRef[i]){minIndexRef=i;minRef=timesRef[i];}
        else if(maxRef < timesRef[i]) {maxIndexRef=i;maxRef=timesRef[i];}
    }
    char minCharRef = alph[minIndexRef];
    char maxCharRef = alph[maxIndexRef];
////////////////////////////////////////////////////
    int  maxCrypted,minCrypted,minIndexCrypt,maxIndexCrypt;

    minCrypted=timesCrypted[0];
    maxCrypted=timesCrypted[0];

    for(int i=1;i<26;i++)
    {
        if(minCrypted > timesCrypted[i]){ minIndexCrypt=i; minCrypted=timesCrypted[i];}
        else if(maxCrypted < timesCrypted[i]){maxIndexCrypt=i; maxCrypted=timesCrypted[i];}
    }
    char minCharCrypted = alph[minIndexCrypt];
    char maxCharCrypted = alph[maxIndexCrypt];

////////////////////////////////////////////////////

    printf("Min Char Ref: %c\tMin Char Crypted: %c",minCharRef,minCharCrypted);
    printf("\nMax Char Ref: %c\tMax Char Crypted: %c\n\n",maxCharRef,maxCharCrypted);
    int minKayirma=minCharRef-minCharCrypted;
    int maxKayirma=maxCharRef-maxCharCrypted;
////////////////////////////////////////////////////
    if(minKayirma==maxKayirma){

        char ch1;
        FILE *fpW1 = fopen(output, "w");
        if (fpW1 == NULL){
            printf("Error opening the file %s", output);
            return -1;
        }
        printf("Kayirma miktari %d olarak tespit edilmistir.\n sCozumlenmis metin %s dosyasina yazilmistir.", output,minKayirma);
        FILE *filePointerR1 = fopen(inputCrypted, "r");

        if (filePointerR1 == NULL)printf("%s is not available \n",inputCrypted);
        else
        {
            printf("\n");
            while ((ch1 = fgetc(filePointerR1)) != EOF)
            {

                if((ch1+maxKayirma)>122){
                    fputc(ch1+maxKayirma-25, fpW1);
                }else if((ch1+maxKayirma)<97){
                    fputc(ch1+maxKayirma+26, fpW1);
                }else fputc(ch1+maxKayirma, fpW1);
            }
        }
        fclose(filePointerR1);
        fclose(fpW1);

    }
////////////////////////////////////////////////////
    else{
        char output1[100];
        output[strlen(output)-4]='\0';
        strncpy(output1,output,sizeof(output1));
        char temp1[]="_1.txt";
        strcat(output1, temp1);

        char ch;
        FILE *fpW = fopen(output1, "w");
        if (fpW == NULL){
            printf("Error opening the file %s", output1);
            return -1;
        }

        printf("Kayirma miktari %d (en sik harf) ve %d (en seyrek harf) olarak tespit edilmistir.",maxKayirma,minKayirma);


        FILE *filePointerR = fopen(inputCrypted, "r");

        if (filePointerR == NULL)printf("%s is not available \n",inputCrypted);
        else
        {
            printf("\n");
            while ((ch = fgetc(filePointerR)) != EOF)
            {

                if((ch+maxKayirma)>122){
                    fputc(ch+maxKayirma-25, fpW);
                }else if((ch+maxKayirma)<97){
                    fputc(ch+maxKayirma+26, fpW);
                }else fputc(ch+maxKayirma, fpW);
            }
        }
        fclose(filePointerR);
        fclose(fpW);
/////////////////////////////////
        char output2[100];
        strncpy(output2,output,sizeof(output2));
        char temp2[]="_2.txt";
        strcat(output2, temp2);

        char chMin;

        FILE *fpW2 = fopen(output2, "w");
        if (fpW2 == NULL){
            printf("Error opening the file %s", output2);
            return -1;
        }

        FILE *filePointerR2 = fopen(inputCrypted, "r");
  printf("Cozumlenmis metin %s ve %s dosyalarina yazilmistir\n",output1,output2);
        if (filePointerR2 == NULL)printf("%s is not available \n",inputCrypted);

        else
        {
            printf("\n");
            while ((chMin = fgetc(filePointerR2)) != EOF)
            {
                if((chMin+minKayirma)>122){
                    fputc(chMin+minKayirma-25, fpW2);
                }else if((chMin+minKayirma)<97){
                    fputc(chMin+minKayirma+26, fpW2);
                }else fputc(chMin+minKayirma, fpW2);
            }
        }
        fclose(filePointerR2);
        fclose(fpW2);
    }

    return 0;
}
