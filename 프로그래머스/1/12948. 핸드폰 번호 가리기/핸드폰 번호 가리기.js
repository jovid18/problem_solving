function solution(phone_number) {
  let str = 'Hello, world!';
  let result = str.substring(5);
  let answer = '';
  const len = phone_number.length - 4; 
  answer = '*'.repeat(len) + phone_number.slice(-4);

  return answer;
}
