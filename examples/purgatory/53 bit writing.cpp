    /* purgatory */
  public:
    void display_data_53(const uint8_t data[7]) {
      /*
      byte b = data[0]; b[x] == (b & (1 << x)) >> x 
      data = {a, b, c, d, e, f, g}
      
      BATTERIE = g[4]
      [SEC]    = g[5]
      PROG     = 
      MEM      = d[6]
      CHAN     = 
      CLOCK    = d[7]
      CLOCK/   = 
      g[3] not relevant

             -                               
            | |                             
       g[7]  -                                   
       g[6] | | f[1]          
       f[0]  -                  
                 
             -               
            | |        
       f[3]  -          
       f[2] | | f[5]
       f[4]  -   
      
             -                               
            | |                             
       f[7]  -                                   
       f[6] | | e[1]          
       e[0]  -                  
                 
             -               
            | |        
       e[3]  -          
       e[2] | | e[5]
       e[4]  -   

             -                               
            | |                             
       e[7]  -                                   
       e[6] | | d[1]          
       d[0]  -                  
                 
             -               
            | |        
       d[3]  -          
       d[2] | | d[5]
       d[4]  -   

             -                               
            | |                             
       c[1]  -                                   
       c[0] | | c[4]          
       c[3]  -                  
                 
             -               
            | |        
       c[5]  -          
       c[4] | | c[7]
       c[6]  -   

             -                               
            | |                             
       b[1]  -                                   
       b[0] | | b[4]          
       b[3]  -                  
                 
             -               
            | |        
       b[5]  -          
       b[4] | | b[7]
       b[6]  -   

             -                               
            | |                             
       a[1]  -                                   
       a[0] | | a[4]          
       a[3]  -                  
                 
             -               
            | |        
       a[5]  -          
       a[4] | | a[7]
       a[6]  -   
                     
      */
      uint8_t data1[7];
      for (int i = 0; i < 7; i++) data1[i] = data[i];
      data1[6] &= 248;
      data1[6] |= 0;
      display_bits(data1);
    }
