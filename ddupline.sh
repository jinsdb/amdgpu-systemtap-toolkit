#!/bin/bash
#arr=("blueviolet" "chocolate" "cyan" "green" "darkorange" "darkslateblue" "deeppink" "firebrick")

awk '!visited[$0]++' $1 > d_$1
last_line=`cat d_$1|wc -l`
awk '{
  color[0]="purple3";
  color[1]="red";
  color[2]="orange";
  color[3]="gold" ;
  color[4]="green";
  color[5]="blue";
  color[6]="indigo";


  if(NR>4 && NR!="'$last_line'"){
    x[$1]++;
    sub(/.{1}$/,"");
    num=x[$1];
    print($0,"[label="""num""",color=\""""color[num%7]"""\"];")
  }else{
    print($0)
  }
}' d_$1 > $1