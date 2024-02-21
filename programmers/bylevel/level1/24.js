function solution(s) {
  // 문자열 내림차순으로 배치하기
  // 대문자는 소문자보다 작은 것으로 간주한다.
  // 문자를 정렬할때는 아스키코드를 사용
  // Ex) 즉, 이미 대문자가 소문자보다 작은거로 설정되어있음.
  // A 65 B 66 C 67... Z 90
  // a 97 b 98 c 99 ...  z 122
  // 요약 : A(65) => Z(90) => a(97) => z(122)
  // 문제에서는 큰거에서 작은순으로 나열하라 햇으므로
  // 문제 :z(122) => a(97) =>Z(90) =>A(65) 
  let answer = '';

  answer = s.split('').sort().reverse().join('');

  return answer;
}
let s = 'azAZzZaA';
let sorts = s.split('').sort();
console.log(sorts);
console.log(solution(s));

// sort() : 자체적으로 대/소문자 정렬
//유니코드 : 문자를 숫자처럼 다루는 코드
//sort를 이용하려면 문자를 유니코드로 바꿔주는 함수를 이용하면 돈다.