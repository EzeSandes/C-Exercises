    int rExponential(int base, int exp)
    {
        if(exp == 0)
            return 1;

        return base * rExponential(base, exp - 1);
    }
