char *ft_conversion_d(int n, int j, char *str)
{
    int z_flag;
    int min;
    int max;
    int t_flag;
    int mom;

    z_flag = 0;
    t_flag = 0;
    mom = 0;
    while (str[j] != 'd')
    {
        if (str[j] == '0')
            z_flag = 1;
        if (str[j] == '-')
            t_flag = 1;
        if (str[j] == '.')
            mom = 1;
        if (str[j] >= 1 && str[j] <= 9)
        {
            if (mom == 0)
            {
                min = ft_atoi((*str) + j);
                j+= (ft_strlen(ft_atoi((*str) + j)) - 1);
            }
            if (mom == 1)
            {
                max = ft_atoi((*str) + j);
                j += (ft_strlen(ft_atoi((*str) + j)) - 1);
            }
        }
        j++;
    }
}