class urlfy{
    
    static int max = 1000; //max length of string
    
    
    //using stringBuffer O(n2)
    public static void replaceSpaces(String input) {
        StringBuffer str = new StringBuffer(input);
    for (int i=0; i<input.length(); i++) {
      if (input.charAt(i) == ' ') {
        str.setCharAt(i,'c');
      }
    }
    System.out.println(str);
  }
  public static char[] replaceSpaceswithoutbuffer(String str){
    char []ch = str.toCharArray();
    int spacecnt = 0, i = 0;
        for(i=0;i<ch.length;i++){
            if(ch[i]==' '){
                spacecnt++;
            }
        }
        while(ch[i-1]==' '){
            spacecnt--;
            i--;
        }
        int newlength = i+2*spacecnt;
        if(newlength>max){
          System.out.println(-1);
        }
        int index =  newlength-1;
        char[] old_str = ch;
        ch = new char[newlength];
        for (int j = i - 1; j >= 0; j--)
        {
 
            // inserts %20 in place of space
            if (old_str[j] == ' ')
            {
                ch[index] = '0';
                ch[index - 1] = '2';
                ch[index - 2] = '%';
                index = index - 3;
            }
             
            else
            {
                ch[index] = old_str[j];
                index--;
            }
        }
        return ch;

  }
  public static void main(String[] args)
  {
    String input = "Mr John Smith";
    replaceSpaces(input);
    char [] ch = replaceSpaceswithoutbuffer(input);
    for (int i = 0; i < ch.length; i++)
    System.out.print(ch[i]);
  }
    
}