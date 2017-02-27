#include<iostream>

#include<time.h>

#include<fstream>

using namespace std;

char command[40]="7z x ";

char filename[20]="test.7z";

char FINAL[40]=" ";

char guess[11]=" ";

char temp[2]=" ";

int c=1;

unsigned long int h=0;

class hack {
      
                struct node {
                       
                                int t;
                                
                                node *left;
                                
                                }*unit;
                                
                public:
                                
                hack();
                
                void add();
                
                void process(node *s);
                
                void display(node *m);
                
                };
                
hack::hack()

{
            
            unit=NULL;
         
}

void hack::add()

{
     
     time_t start, end;
     
     tm *tm;
     
     start=time(NULL);

     ofstream binout ("time.bin", ios::binary|ios::app);
     
     ofstream textout ("time.txt", ios::app);
     
     binout.write((char*)&start, sizeof(time_t));
     
     tm=localtime(&start);
     
     cout<<"Cracking started "<<tm->tm_hour<<":"<<tm->tm_min<<":"<<tm->tm_sec
     
             <<" on "<<tm->tm_mon<<"."<<tm->tm_mday<<"."<<tm->tm_year+1900<<endl;
     
     textout<<"Cracking started "<<tm->tm_hour<<":"<<tm->tm_min<<":"<<tm->tm_sec
     
             <<" on "<<tm->tm_mon<<"."<<tm->tm_mday<<"."<<tm->tm_year+1900<<endl;
     
    unit=new node;
    
    unit->t=-1;
    
    unit->left=NULL;
    
    while (1)     // Just a test run
    
    {
           
           process(unit);
           
           if (unit==NULL)
              
              cout<<"null\n";
              
           else
               
               cout<<"not null\n"; */
               
           strcpy(guess, " ");
           
           display(unit);
           
           cout<<guess<<endl;
           
           strcpy(FINAL, command);
           
           int m;
           
           for (m=1; guess[m]!='\0'; m++)
     
               guess[m-1]=guess[m];
         
           guess[m-1]='\0';
           
           strcat(FINAL, guess);
           
           int flag=0;
           
           flag=system(FINAL);
           
           system("cls");
           
           if (flag==0)
              
              break;
                 
           h++;
           
           
    }
    
    end=time(NULL);
    
    tm=localtime(&end);
    
    binout.write((char*)&end, sizeof(time_t));
    
    cout<<"Cracking ended "<<tm->tm_hour<<":"<<tm->tm_min<<":"<<tm->tm_sec
     
             <<" on "<<tm->tm_mon<<"."<<tm->tm_mday<<"."<<tm->tm_year+1900<<endl;
     
    textout<<"Cracking ended "<<tm->tm_hour<<":"<<tm->tm_min<<":"<<tm->tm_sec
     
             <<" on "<<tm->tm_mon<<"."<<tm->tm_mday<<"."<<tm->tm_year+1900<<endl;
             
             cout<<"Your password was\n";
               
               cout<<guess<<endl;
               
     cout<<h<<" comparisons were made and \n";
               
     textout<<"Time taken was "<<end-start<<" seconds "<<endl;
     
     textout<<"The password was: "<<guess;
     
     textout<<endl<<endl;
     
     cout<<endl;
     
     class pw {
           
                         public:
           
                         char pass[5];
                         
           }p;
           
     strcpy(p.pass, guess);
     
     binout.write((char*)&p, sizeof(pw));
             
     binout.close();
     
     textout.close();
     
     cout<<"Your password was cracked in "<<end-start<<" seconds\n";
    
    cin.get();
    
    return;
           
}
           
void hack::process(node *s)

{
     
   
                   
                   if (s==NULL||s->t==-1)
                   
                   {
                                         
                           cout<<"Phase "<<c++<<"...\n";
                               
                               s->t=32;
                               
                               node *k;
                               
                               k=new node;
                               
                               k->t=-1;
                               
                               k->left=NULL;
                               
                               s->left=k;
   
							   return;
                               
                   }                  
                   
                   if (s->t<126)
                   
                   {
                                
                                if (s->t==37)
                                
                                {
                                             s->t=39;
                                             
                                             return;
                                             
                                }
                                
                                 
                                 s->t++;
                                 
                                 return;
                                 
                   }
                   
                   else
                   
                   {
                       
                                 s->t=32;
                                 
                                 process(s->left);
                                 
                                 return;
                                 
                    }
                    
}

void hack::display(node *m)

{
     
     
    if (m!=NULL)
    
    {
                 
                display(m->left);
                
                temp[0]=char(m->t);
                
                temp[1]='\0';
                
               if (strcmp(guess, " ")==0)
                
                   strcpy(guess, temp);
                   
                else
                
                    strcat(guess, temp);
    
    }
    
    return;
    
}

int main()

{
    
    hack s;
    
    system("@echo off");
    
    system("TITLE Zip file cracker - (c)2010 gtaddict");
    
    cout<<"Enter the name of the file to be cracked\n";
    
    gets(filename);
    
    strcat(command, filename);
    
    strcat(command, " -p");
    
    cout<<"\nAre you ready to continue?\n";
    
    cin.get();
    
    try
    
    {
    
    s.add();
    
    }
    
    catch(...)
    
    {
           
           cout<<"There's been an overload...saving file. Resume later.\n";
           
           ofstream f ("resume.dat", ios::app);
           
           f<<endl<<guess<<endl<<endl;
           
           f.close();
           
           exit(-1);
           
    }
    
    return 0;
    
}
