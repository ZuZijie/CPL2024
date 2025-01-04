#include "ramfs.h"
#include "shell.h"
#ifndef ONLINE_JUDGE
  #define print(...) printf("\033[31m");printf(__VA_ARGS__);printf("\033[0m");
#else
  #define print(...) 
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ex "export PATH="
int sls(const char *pathname) {
  node *pt_node=(node *)malloc(sizeof(node));
  if(pathname == NULL) pt_node=root;
  else {
      pt_node = find(pathname,root);
      if(pt_node == NULL) {
          if(doContainFile(pathname)==0) {
            print("ls: cannot access '%s': Not a directory\n",pathname);
            return 0;
          }
          printf("ls: cannot access '%s': No such file or directory\n",pathname);
          return 0;
      }

    if(pt_node->type==DNODE)
     {
       printf("ls: cannot access '%s: Not a directory\n",pathname);
       return 0;
     }
  }
    for(int i=0;i<4096;i++) {
      if(pt_node->dirents[i]!=NULL) {
        printf("%s ",pt_node->dirents[i]->name);
      }
    }
  printf("\n");
  return 0;
}

int scat(const char *pathname) {

    if(find(pathname,root)==NULL) {
      if(doContainFile(pathname)==0) {
        printf("cat: %s: Not a directory\n",pathname);
        return 0;
      }
      printf("cat: %s: No such file or directory\n",pathname);
      return 0;
    }
  node *pt_node=(node *)malloc(sizeof(node));
  pt_node=find(pathname,root);
  if(find(pathname,root)->type==DNODE) {
    printf("cat: %s: Is a directory\n",pathname);
    return 0;
  }
  else {
    char *output=(char *)malloc(sizeof(char)*4096);
    memset(output,0,4096);
    output=(char*)pt_node->content;
    for(int i=0;i<pt_node->size;i++)printf("%c",output[i]);
    printf("\n");
  }
  return 0;
}

int smkdir(const char *pathname) {
    node *pt_node=(node *)malloc(sizeof(node));
    pt_node=find(pathname,root);
  if(pt_node!=NULL) {
    printf("mkdir: cannot create directory '%s': File exists\n",pathname);
    return 0;
  }
  pt_node=findFatherNode(pathname);
  if(pt_node==NULL) {
    if(doContainFile(pathname)==0) {
      printf("mkdir: cannot create directory '%s': Not a directory\n",pathname);
      return 0;
    }
    printf("mkdir: cannot create directory '%s': No such file or directory\n",pathname);
    return 0;
  }

  rmkfile(pathname);
  return 0;
}

int stouch(const char *pathname) {
  if(find(pathname,root)!=NULL) return 0;
  if(findFatherNode(pathname)==NULL) {
    if(doContainFile(pathname)==0) {
      printf("touch: cannot touch '%s': Not a directory\n",pathname);
      return 0;
    }
  printf("touch: cannot touch '%s': No such file or directory\n",pathname);
  }
  rmkfile(pathname);
  return 0;
}

int secho(const char *content) {
  print("echo %s\n", content);

}

int swhich(const char *cmd) {
  print("which %s\n", cmd);

}

void init_shell() {
    node *bashrc=find("/home/ubuntu/.bashrc",root);
    char *command=(char *)calloc(bashrc->size,1);
    command=(char *)bashrc->content;
    PATH=(char *)calloc(1000,sizeof(char));

    for(int i=0;i<bashrc->size-sizeof(ex);i++) {
        int valid=1;
        for(int j=0;j<sizeof(ex);j++) {
          if(command[i+j]!=ex[j]) {
            valid=0;
            break;
          }
        }
        if(valid) {
            char *temp=(char *)calloc(bashrc->size,sizeof(char));
            int posi=0;
            while(command[i+posi]!='\n' && i+posi<bashrc->size) {
              temp[posi]=command[i+posi];
              posi++;
            }
            temp[posi+1]='\0';
            PATH=update_path(PATH,temp);
        }
    }
}

void close_shell() {
    free(PATH);
}
int doContainFile(const char *pathname) {
  node *current_node=(node *)malloc(sizeof(node));
  current_node=findFatherNode(pathname);
  char *current_node_name=pathname;
  while(find(current_node_name,root)==NULL && current_node!=NULL) {
    current_node_name=FatherNodePathName(current_node_name);
  }
  while(findFatherNode(current_node )!=root && current_node!=root) {
    if(current_node->type==DNODE) {
      // printf("%s: Not a directory\n",pathname);
      return 0;
    }
    current_node_name=FatherNodePathName(current_node_name);
    current_node=find(current_node_name,root);
  }
  return 1;
}
char* update_path(char *current_path,char *command) {
  const char *prefix = "export PATH=";
  const char *path_value = command + strlen(prefix);
  char *new_path = NULL;
  if (strchr(path_value, '$') != NULL) {
    if (strstr(path_value, "$PATH:") == path_value) {
      // "$PATH:" 前缀
      new_path = malloc(strlen(current_path) + strlen(path_value) - 5 + 1); // -5 去掉 "$PATH" 的长度，+1 包括 "\0"
      sprintf(new_path, "%s:%s", current_path, path_value + 6);
    } else if (strstr(path_value, ":$PATH") != NULL) {
      // ":$PATH" 后缀
      const char *pos = strstr(path_value, ":$PATH");
      size_t new_length = (pos - path_value) + strlen(current_path) + 1;
      new_path = malloc(new_length + 1);
      strncpy(new_path, path_value, pos - path_value);
      new_path[pos - path_value] = '\0';
      strcat(new_path, ":");
      strcat(new_path, current_path);
    } else {
      return NULL;
    }
  } else {
    new_path = strdup(path_value);
  }

  return new_path;
}