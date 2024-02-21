function tentothree(n) {
  let str = ''; //나머지를 담을 배열을 선언
  while (n !== 0) {
    let remain = n % 3; // 나머지
    str = String(remain) + str;
    let share = Math.floor(n / 3); //몫
    n = share;
  }
  return str;
}

function threetoten(s) {
  let ret = 0n;
  for (let i = 0; i < s.length; ++i) {
    ret += BigInt(Number(s[i])) * 3n ** BigInt(s.length - i - 1);
  }
  return ret;
}
function solution(n) {
  let num3 = tentothree(n);
  let reversenum3 = [...num3].reverse().join('');
  let answer = threetoten(reversenum3);
  return answer;
}
// 30번에서 만든 3진법을 다시 10진법으로 변환
// 3진수에서 10진수로 변환하는 방법은 각 자릿수를 해당 자릿값과 곱한 후 모두 더하는 것입니다.
// 41->1112
//  1(27) 1(9) 1(3) 2(1)  = 1*27+1*9+1*3+2*1=41 , ()안의 숫자는 3의 배수

//3진법을 10진법으로 바꾸는 함수
function threetoten(n) {
    let a = n.split('')
}
    
  
console.log(threetoten(1112));