function solution(phone_number) {
  let answer = '';
  const len = phone_number.length - 4; //len은 phone_number의 길이 -4
  answer = '*'.repeat(len) + phone_number.slice(-4);
  return answer;
}
