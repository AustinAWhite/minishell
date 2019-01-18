#include "minishell.h"

int catch_ctrl_c = 0;

void        ctrl_c_interupt(int num)
{
    catch_ctrl_c = 1;
}