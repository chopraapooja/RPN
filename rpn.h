int split(char*,char***,char*);
typedef struct status
{
  int error;
  int result;
} Status;

Status evaluate(char* expression);