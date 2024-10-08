class Solution(object):
    def spiralMatrixIII(self, rows, cols, rStart, cStart):
        i, j = rStart, cStart
        diri, dirj = 0, 1  # Starting direction is to the right
        twice = 2
        res = []
        moves = 1
        next_moves = 2

        while len(res) < (rows * cols):
            if (-1 < i < rows) and (-1 < j < cols):
                res.append([i, j])
            
            i += diri
            j += dirj
            moves -= 1

            if moves == 0:
                diri, dirj = dirj, -diri  # Rotate direction 90 degrees clockwise
                twice -= 1
                if twice == 0:
                    twice = 2
                    moves = next_moves
                    next_moves += 1
                else:
                    moves = next_moves - 1

        return res
