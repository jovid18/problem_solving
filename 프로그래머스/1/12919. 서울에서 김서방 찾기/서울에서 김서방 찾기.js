function solution(seoul) {
  //서울에서 김서방 찾기
  //seoul이 배열이니까 forEach로 순회하고,
  //원소가 Kim일때 index를 저장하고
  //`김서방은 ${index}에 있다`리턴 해주면 될것 같습니다.
  for (let i = 0; i < seoul.length; i++) {
    if (seoul[i] === 'Kim') return `김서방은 ${i}에 있다`;
  }
}
