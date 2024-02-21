function solution(n) {
    //성현님
  let answer = '';
  let a = '수박';
  if (n % 2 === 0) {
    answer += a.repeat(n / 2);
  } else if (n % 2 === 1) {
    answer += a.repeat((n - 1) / 2);
    answer += '수';
  }
  return answer;
}
//repeat하고  마지막 박을 빼는 방법도 있음