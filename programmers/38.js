function solution(array, commands) {
  return commands.map(([start, end, position]) => {
    const slicedAndSorted = array.slice(start - 1, end).sort((a, b) => a - b);
    return slicedAndSorted[position - 1];
  });
}
