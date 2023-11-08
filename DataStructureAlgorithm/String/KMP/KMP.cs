using System;
using static System.Console;
namespace t7
{
    class MainApp
    {
        static void Main(string[] args)
        {
            int p = KMP("zabcabxaccabcabdef", "abcabd");
            WriteLine($"\n찾은 문자열의 위치는 {p}");
        }
        static int KMP(string target, string p){
            int pt = 1;
            int pp = 0;
            int[] check = new int[p.Length+1];
            check[pt]=0;
            while(pt!=p.Length){
                if(p[pt] == p[pp]) check[++pt] = ++pp;
                else if(pp==0) check[++pt] = pp;
                else pp = check[pp];
            }
            Write("check table: ");
            foreach(var i in check)
                Write(i+" ");
            pt = pp = 0;
            while(pt!=target.Length && pp!=p.Length){
                if(target[pt]==p[pp]){
                    pt++;
                    pp++;
                }
                else if(pp==0) pt++;
                else pp = check[pp];
            }
            if(pp==p.Length) return pt-pp;
            return -1;
        }
    }
}
