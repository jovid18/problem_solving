function solution(num) {
  //num을  2로 나눈 나머지가 0일때는 "Even" 1일때는 "Odd"
  return num % 2 === 0 ? 'Even' : 'Odd';

  // var answer = '';
  // if (num % 2 === 0) {
  //   return 'Even';
  // } else {
  //   return 'Odd';
  // }
}

console.time('시작');
solution(3);
console.timeEnd('시작');
