function solution(s) {
  // 정규 표현식을 분석해보면 다음과 같다.
  // 먼저 new RegExp(...) 부분으로 새로운 정규 표현식 객체를 생성한다.
  // 이후 내부 부분은 ^\\d{${s.length}}$인데
  // 처음의 ^와 끝의 $은 문자열의 시작과 문자열의 끝을 의미하며 \\d는 숫자 임을 의미하며 {{s.length}}은 s.length만큼 반복되어야 함을 의미한다.
  if (s.length !== 4 && s.length !== 6) {
    return false;
  }
  const regex = new RegExp(`^\\d{${s.length}}$`);
  return regex.test(s);
}
