function solution(phone_number) {
  //핸드폰 번호 가리기
  //phone_number의 length -4만큼 *를 추가해주고
  //나머지는 4자리는 phonu_number에서 떼오는 걸로

  let answer = '';
  const len = phone_number.length - 4; //len은 phone_number의 길이 -4
  answer = '*'.repeat(len) + phone_number.substring(len);

  return answer;
}

// slice
// slice(-4,phone_number.length)
