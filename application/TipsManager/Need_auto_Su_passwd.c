#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/***********************************************
*    Function name   :  Need_auto_Su_passwd 
*                       
*    Description     :  Get switchname from cmd_str with the help of en_cmd('su' default) 
*    Param           :  
*                       switchname: login account name 
*    Return          :  
*                       succ: 0 fail: 1 switchname: su - (switchname) 
*    Author          :  yusq
*    Create date     :  2018-07-20 11:40:09
***********************************************/
static int Need_auto_Su_passwd(char *cmd_str,char *en_cmd, char **switchname)
{
   if (strlen(en_cmd) == 0)
   {
           return 1;
   }
   int ret_limit=0;
   int i;
   int prefix_len=0;
   char *p=strstr(cmd_str,en_cmd);
   printf("****************  p[%s] *****************\n", p);
   if(p)
   {
      prefix_len=p-cmd_str;
      printf("****************  prefix_len[%d] *****************\n", prefix_len);
     for(i=0;i<prefix_len;i++)
     {
       if(cmd_str[i]!=0x20 && i!=0)
       {
         ret_limit=1;
         break;
       }
     }
   }

   int suffix_cmd=prefix_len+strlen(en_cmd);
   printf("****************  suffix_cmd[%d] *****************\n", suffix_cmd);
   printf("****************  cmd_str+prefix_len[%s] *****************\n", cmd_str+prefix_len);
   printf("****************  strcmp(cmd_str+prefix_len,en_cmd)[%d] *****************\n", strcmp(cmd_str+prefix_len,en_cmd));
   if(!ret_limit&&p && (cmd_str[suffix_cmd]==0x20||!strcmp(cmd_str+prefix_len,en_cmd)))
   {
      printf("****************  *switchname_after_if[%s] switchname[%x] *****************\n", *switchname, switchname);
           if (switchname)
           {
                   if (*switchname)
                   {
                           free(*switchname);
                           *switchname = NULL;
                   }
                   printf("**************** strcmp(en_cmd,sudo)[%d] *****************\n", strcmp(en_cmd,"sudo"));
                   if(strstr(cmd_str,"sudo"))
                   { 
                     *switchname = "yusq";
                     return 0; 
                   } 
                   //获取用户切换，输入的名字
                   p += strlen(en_cmd);
                   printf("***************|||||||||||||||||||||||****************\n", p);
                   printf("****************  p[%s] *****************\n", p);
                   //跳过空格
                   for (; *p != 0 ; ++p)
                   {
                           if (*p != ' ')
                           {
                                   break;
                           }
                   }
                   if (strlen(p))
                   {
                           //跳过空格和-
                           for (; *p != '\0'; ++p)
                           {
                                   if (*p == ' ' || *p == '-')
                                   {
                                   }
                                   else
                                   {
                                           break;
                                   }
                           }
                          *switchname = strdup(p);
                          printf("****************  switchname_before_cancel_space[%s] *****************\n", *switchname);
                          //去除换行,空格
                          int i;
                          char *p = *switchname;
                           for (i = 0; *p != '\0';p++)
                            {
                                    if (*p == ' ' || *p == '\r' || *p == '\n')
                                    {
                                            *p = 0;
                                            break;
                                    }
                            }
                            printf("****************  switchname[%s] *****************\n", *switchname);
                    }
            }
            return 0;
    }
    return 1;
}
 


int main(int argc, char *argv[])
{
  char *cmd = "  sudo -i";
  char *switchname = NULL;
   
  int need_input_passwd=Need_auto_Su_passwd(cmd,"sudo", &switchname);

  printf("****************  need_input_passwd[%d] switchname[%s] *****************\n",need_input_passwd, switchname);
  return 0;
}
