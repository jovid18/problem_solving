//실패 예시
function solution(seoul) {
  seoul.forEach((element, idx) => {
    if (element === 'Kim') return `김서방은 ${idx}에 있다`;
  });
}
