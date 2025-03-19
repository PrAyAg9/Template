#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <tuple>
#include <climits>
#include <string>
#include <unordered_set>
#include <algorithm>

// 4) snake
#include <map>
#include <set>


using namespace std;

// ------- ------- ------ FUNCTIONS & VARIOUS PROBLEMS -------- ---------- ----------


// Floood Fill 
// // Helper function for DFS
// void dfs(vector<vector<int>>& image, int x, 
//     int y, int oldColor, int newColor) {

// // Check boundary conditions and color match
// if (x < 0 || x >= image.size() || y < 0 || 
//    y >= image[0].size() || image[x][y] != 
//    oldColor) {
//    return;
// }

// // Change the color
// image[x][y] = newColor;

// // Visit all adjacent pixels
// dfs(image, x + 1, y, oldColor, newColor);
// dfs(image, x - 1, y, oldColor, newColor);
// dfs(image, x, y + 1, oldColor, newColor);
// dfs(image, x, y - 1, oldColor, newColor);
// }

// vector<vector<int>> floodFill(
// vector<vector<int>>& image, int sr, 
// int sc, int newColor) {

// // If starting pixel already has the new color
// if (image[sr][sc] == newColor) {
//    return image;
// }

// // Call DFS with the starting pixel's original color
// dfs(image, sr, sc, image[sr][sc], newColor);

// return image;
// }

// void printArray(vector<vector<int>>& image) {
// for (auto& row : image) {
//    for (auto& pixel : row) {
//        cout << pixel << " ";
//    }
//    cout << "\n";
// }
// }


// class Graph
// {
//     int V; // No. of vertices
//     // In a weighted graph, we need to store vertex
//     // and weight pair for every edge
//     list< pair<int, int> > *adj;
 
// public:
//     Graph(int V); // Constructor
 
//     // function to add an edge to graph
//     void addEdge(int u, int v, int w);
 
//     // prints shortest path from s
//     void shortestPath(int s, int W);
// };
 
// // Allocates memory for adjacency list
// Graph::Graph(int V)
// {
//     this->V = V;
//     adj = new list< pair<int, int> >[V];
// }
 
// // adds edge between u and v of weight w
// void Graph::addEdge(int u, int v, int w)
// {
//     adj[u].push_back(make_pair(v, w));
//     adj[v].push_back(make_pair(u, w));
// }
 
// // Prints shortest paths from src to all other vertices.
// // W is the maximum weight of an edge
// void Graph::shortestPath(int src, int W)
// {
//     /* With each distance, iterator to that vertex in
//     its bucket is stored so that vertex can be deleted
//     in O(1) at time of updation. So
//     dist[i].first = distance of ith vertex from src vertex
//     dist[i].second = iterator to vertex i in bucket number */
//     vector<pair<int, list<int>::iterator> > dist(V);
 
//     // Initialize all distances as infinite (INF)
//     for (int i = 0; i < V; i++)
//         dist[i].first = INF;
 
//     // Create buckets B[].
//     // B[i] keep vertex of distance label i
//     list<int> B[W * V + 1];
 
//     B[0].push_back(src);
//     dist[src].first = 0;
 
//     //
//     int idx = 0;
//     while (1)
//     {
//         // Go sequentially through buckets till one non-empty
//         // bucket is found
//         while (B[idx].size() == 0 && idx < W*V)
//             idx++;
 
//         // If all buckets are empty, we are done.
//         if (idx == W * V)
//             break;
 
//         // Take top vertex from bucket and pop it
//         int u = B[idx].front();
//         B[idx].pop_front();
 
//         // Process all adjacents of extracted vertex 'u' and
//         // update their distanced if required.
//         for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
//         {
//             int v = (*i).first;
//             int weight = (*i).second;
 
//             int du = dist[u].first;
//             int dv = dist[v].first;
 
//             // If there is shorted path to v through u.
//             if (dv > du + weight)
//             {
//                 // If dv is not INF then it must be in B[dv]
//                 // bucket, so erase its entry using iterator
//                 // in O(1)
//                 if (dv != INF)
//                     B[dv].erase(dist[v].second);
 
//                 // updating the distance
//                 dist[v].first = du + weight;
//                 dv = dist[v].first;
 
//                 // pushing vertex v into updated distance's bucket
//                 B[dv].push_front(v);
 
//                 // storing updated iterator in dist[v].second
//                 dist[v].second = B[dv].begin();
//             }
//         }
//     }
 
//     // Print shortest distances stored in dist[]
//     printf("Vertex Distance from Source\n");
//     for (int i = 0; i < V; ++i)
//         printf("%d     %d\n", i, dist[i].first);
// }

// 1) Shark Strength - 
// struct State {
//     int x, y, time, strength;
// };

// bool isValid(int x, int y, int N, int M) {
//     return x >= 0 && x < N && y >= 0 && y < M;
// }

// int main() {
//     int N, M;
//     cin >> N >> M;

//     vector<vector<int>> sharkStrength(N, vector<int>(M));
//     vector<vector<int>> travelTime(N, vector<int>(M));

//     pair<int, int> source, destination;

//     // Read shark strengths and identify source (S) and destination (D)
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < M; j++) {
//             string cell;
//             cin >> cell;
//             if (cell == "S") {
//                 source = {i, j};
//                 sharkStrength[i][j] = 0;
//             } else if (cell == "D") {
//                 destination = {i, j};
//                 sharkStrength[i][j] = 0;
//             } else {
//                 sharkStrength[i][j] = stoi(cell);
//             }
//         }
//     }

//     // Read travel times
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < M; j++) {
//             cin >> travelTime[i][j];
//         }
//     }

//     int K;
//     cin >> K;

//     vector<vector<int>> minTime(N, vector<int>(M, INT_MAX));
//     vector<vector<int>> maxStrength(N, vector<int>(M, INT_MIN));

//     queue<State> q;
//     q.push({source.first, source.second, 0, K});
//     minTime[source.first][source.second] = 0;
//     maxStrength[source.first][source.second] = K;

//     int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

//     while (!q.empty()) {
//         State current = q.front();
//         q.pop();

//         for (auto dir : directions) {
//             int nx = current.x + dir[0];
//             int ny = current.y + dir[1];

//             if (isValid(nx, ny, N, M)) {
//                 int nextStrength = current.strength - 1;
//                 if (sharkStrength[nx][ny] > 0) {
//                     if (nextStrength >= sharkStrength[nx][ny]) {
//                         nextStrength -= sharkStrength[nx][ny];
//                     } else {
//                         continue;
//                     }
//                 }

//                 int nextTime = current.time + travelTime[nx][ny];

//                 if (nextStrength >= 0 && (nextTime < minTime[nx][ny] || (nextTime == minTime[nx][ny] && nextStrength > maxStrength[nx][ny]))) {
//                     minTime[nx][ny] = nextTime;
//                     maxStrength[nx][ny] = nextStrength;
//                     q.push({nx, ny, nextTime, nextStrength});
//                 }
//             }
//         }
//     }

//     int destTime = minTime[destination.first][destination.second];
//     int destStrength = maxStrength[destination.first][destination.second];

//     if (destTime == INT_MAX) {
//         cout << "Not Possible" << endl;
//     } else {
//         cout << destTime << " " << destStrength << endl;
//     }

//     return 0;
// }




// 2) Chess Piece
// Structure to represent a chess piece
// struct ChessPiece {
//     char type; // 'Q', 'R', 'B'
//     int column; // 0 to 7 for 'A' to 'H'
//     int row;    // 0 to 7 for '1' to '8'
    
//     bool operator<(const ChessPiece& other) const {
//         auto typeOrder = [](char c) -> int {
//             if (c == 'Q') return 0;
//             if (c == 'R') return 1;
//             if (c == 'B') return 2;
//             return 3; // Should not happen
//         };
//         if (typeOrder(type) != typeOrder(other.type))
//             return typeOrder(type) < typeOrder(other.type);
//         if (column != other.column)
//             return column < other.column;
//         return row < other.row;
//     }
// };

// // Structure to represent a chessboard position
// struct BoardPosition {
//     vector<ChessPiece> pieces; // Sorted list of pieces
    
//     // Serialize the position into a string for hashing
//     string serialize() const {
//         string serialized;
//         for (const auto &piece : pieces) {
//             serialized += piece.type;
//             serialized += char('A' + piece.column);
//             serialized += char('1' + piece.row);
//             serialized += '|';
//         }
//         return serialized;
//     }
    
//     // Sort pieces in the order Q, R, B
//     void sortPieces() {
//         sort(pieces.begin(), pieces.end());
//     }
// };

// // Function to generate all possible moves for a given piece in a position
// vector<ChessPiece> generateMoves(const BoardPosition &position, const ChessPiece &piece) {
//     vector<ChessPiece> possibleMoves;
//     vector<pair<int, int>> directions;
    
//     if (piece.type == 'Q') {
//         directions = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
//     } else if (piece.type == 'R') {
//         directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
//     } else if (piece.type == 'B') {
//         directions = {{1,1}, {1,-1}, {-1,1}, {-1,-1}};
//     }
    
//     vector<vector<bool>> occupied(8, vector<bool>(8, false));
//     for (const auto &p : position.pieces) {
//         if (p.type != piece.type || p.column != piece.column || p.row != piece.row) {
//             occupied[p.column][p.row] = true;
//         }
//     }
    
//     for (const auto &[dc, dr] : directions) {
//         int newColumn = piece.column + dc;
//         int newRow = piece.row + dr;
//         while (newColumn >= 0 && newColumn < 8 && newRow >= 0 && newRow < 8) {
//             if (occupied[newColumn][newRow]) {
//                 break;
//             }
//             ChessPiece newPiece = piece;
//             newPiece.column = newColumn;
//             newPiece.row = newRow;
//             possibleMoves.push_back(newPiece);
//             newColumn += dc;
//             newRow += dr;
//         }
//     }
//     return possibleMoves;
// }

// // Function to calculate unique board positions after a given number of plies
// int calculateUniquePositions(vector<ChessPiece> initialPieces, int plies) {
//     BoardPosition initialPosition;
//     initialPosition.pieces = initialPieces;
//     initialPosition.sortPieces();
    
//     unordered_set<string> currentLayer;
//     currentLayer.insert(initialPosition.serialize());
    
//     for (int depth = 1; depth <= plies; depth++) {
//         unordered_set<string> nextLayer;
//         for (const auto &posStr : currentLayer) {
//             BoardPosition position;
//             stringstream ss(posStr);
//             string pieceStr;
//             while (getline(ss, pieceStr, '|')) {
//                 if (pieceStr.empty()) continue;
//                 ChessPiece piece;
//                 piece.type = pieceStr[0];
//                 piece.column = pieceStr[1] - 'A';
//                 piece.row = pieceStr[2] - '1';
//                 position.pieces.push_back(piece);
//             }
//             for (const auto &piece : position.pieces) {
//                 vector<ChessPiece> possibleMoves = generateMoves(position, piece);
//                 for (const auto &newPiece : possibleMoves) {
//                     BoardPosition newPosition = position;
//                     for (auto &p : newPosition.pieces) {
//                         if (p.type == piece.type) {
//                             p.column = newPiece.column;
//                             p.row = newPiece.row;
//                             break;
//                         }
//                     }
//                     newPosition.sortPieces();
//                     string newPosStr = newPosition.serialize();
//                     nextLayer.insert(newPosStr);
//                 }
//             }
//         }
//         currentLayer = move(nextLayer);
//     }
    
//     return currentLayer.size();
// }

// int main() {
//     string inputLine;
//     getline(cin, inputLine);
    
//     vector<ChessPiece> initialPieces;
//     stringstream ss(inputLine);
//     string token;
//     while (ss >> token) {
//         ChessPiece piece;
//         piece.type = token[0];
//         piece.column = token[1] - 'A';
//         piece.row = token[2] - '1';
//         initialPieces.push_back(piece);
//     }
    
//     int plies;
//     cin >> plies;
    
//     int result = calculateUniquePositions(initialPieces, plies);
//     cout << result << endl;
// }



// 3) Extracted Volume

// class Cell {
//     public:
//         bool hasLeftWall;
//         bool hasRightWall;
//         bool hasTopWall;
//         bool hasBottomWall;
//         int groupID;
    
//         Cell() : hasLeftWall(false), hasRightWall(false), hasTopWall(false), hasBottomWall(false), groupID(-1) {}
//     };
    
//     class Shape {
//     public:
//         int id;
//         int area;
//         vector<pair<int, int>> cells;
//         bool isExtracted;
//         bool isExtractable;
    
//         Shape(int shapeID) : id(shapeID), area(0), isExtracted(false), isExtractable(false) {}
//     };
    
//     class GridManager {
//     private:
//         int rows, cols, squareSize, wallCount;
//         vector<vector<Cell>> grid;
//         vector<Shape> shapes;
//         int currentShapeID;
    
//         const int dx[4] = { -1, 1, 0, 0 };
//         const int dy[4] = { 0, 0, -1, 1 };
    
//     public:
//         GridManager(int R, int C, int S, int N) : rows(R), cols(C), squareSize(S), wallCount(N), grid(R, vector<Cell>(C)), currentShapeID(0) {}
//         void addWall(int x1, int y1, int x2, int y2) {
//             if (x1 == x2) { 
//                 int x = x1;
//                 int yStart = min(y1, y2);
//                 int yEnd = max(y1, y2);
//                 for (int y = yStart; y < yEnd; y++) {
//                     if (x > 0 && x <= cols)
//                         grid[y][x - 1].hasRightWall = true;
//                     if (x >= 0 && x < cols)
//                         grid[y][x].hasLeftWall = true;
//                 }
//             }
//             else if (y1 == y2) {
//                 int y = y1;
//                 int xStart = min(x1, x2);
//                 int xEnd = max(x1, x2);
//                 for (int x = xStart; x < xEnd; x++) {
//                     if (y > 0 && y <= rows)
//                         grid[y - 1][x].hasBottomWall = true;
//                     if (y >= 0 && y < rows)
//                         grid[y][x].hasTopWall = true;
//                 }
//             }
//         }
    
//         void identifyShapes() {
//             for (int y = 0; y < rows; y++) {
//                 for (int x = 0; x < cols; x++) {
//                     if (grid[y][x].groupID == -1) {
//                         Shape newShape(currentShapeID);
//                         floodFill(x, y, newShape);
//                         shapes.push_back(newShape);
//                         currentShapeID++;
//                     }
//                 }
//             }
//         }
    
//         void floodFill(int startX, int startY, Shape &shape) {
//             queue<pair<int, int>> q;
//             q.push({startX, startY});
//             grid[startY][startX].groupID = shape.id;
//             shape.area++;
//             shape.cells.push_back({startX, startY});
    
//             while (!q.empty()) {
//                 pair<int, int> current = q.front();
//                 q.pop();
//                 int cx = current.first;
//                 int cy = current.second;
    
//                 for (int dir = 0; dir < 4; dir++) {
//                     int nx = cx + dx[dir];
//                     int ny = cy + dy[dir];
    
//                     if (nx < 0 || nx >= cols || ny < 0 || ny >= rows)
//                         continue;
    
//                     bool hasWall = false;
//                     if (dir == 0 && grid[cy][cx].hasLeftWall) hasWall = true;   
//                     if (dir == 1 && grid[cy][cx].hasRightWall) hasWall = true;  
//                     if (dir == 2 && grid[cy][cx].hasTopWall) hasWall = true;       
//                     if (dir == 3 && grid[cy][cx].hasBottomWall) hasWall = true;    
    
//                     if (!hasWall && grid[ny][nx].groupID == -1) {
//                         grid[ny][nx].groupID = shape.id;
//                         shape.area++;
//                         shape.cells.push_back({nx, ny});
//                         q.push({nx, ny});
//                     }
//                 }
//             }
    
//             shape.isExtractable = checkExtractable(shape);
//         }
    
//         bool checkExtractable(const Shape &shape) {
//             for (int yStart = 0; yStart <= rows - squareSize; yStart++) {
//                 for (int xStart = 0; xStart <= cols - squareSize; xStart++) {
//                     bool canFit = true;
//                     for (auto &cell : shape.cells) {
//                         int cellX = cell.first;
//                         int cellY = cell.second;
//                         if (cellX < xStart || cellX >= xStart + squareSize || cellY < yStart || cellY >= yStart + squareSize) {
//                             canFit = false;
//                             break;
//                         }
//                     }
//                     if (canFit)
//                         return true;
//                 }
//             }
//             return false;
//         }
//         pair<int, int> extractShapes() {
//             int extractionTurns = 0;
//             int totalExtractedArea = 0;
    
//             while (true) {
//                 vector<int> availableShapes;
//                 for (auto &shape : shapes) {
//                     if (shape.isExtractable && !shape.isExtracted)
//                         availableShapes.push_back(shape.id);
//                 }
    
//                 if (availableShapes.empty())
//                     break; 
    
//                 int maxArea = 0;
//                 int bestY = rows, bestX = cols;
//                 vector<int> shapesToExtract;
    
//                 for (int yStart = 0; yStart <= rows - squareSize; yStart++) {
//                     for (int xStart = 0; xStart <= cols - squareSize; xStart++) {
//                         int currentArea = 0;
//                         vector<int> tempShapes;
    
//                         for (int shapeID : availableShapes) {
//                             bool fits = true;
//                             for (auto &cell : shapes[shapeID].cells) {
//                                 int cellX = cell.first;
//                                 int cellY = cell.second;
//                                 if (cellX < xStart || cellX >= xStart + squareSize || cellY < yStart || cellY >= yStart + squareSize) {
//                                     fits = false;
//                                     break;
//                                 }
//                             }
//                             if (fits) {
//                                 currentArea += shapes[shapeID].area;
//                                 tempShapes.push_back(shapeID);
//                             }
//                         }
    
//                         if (currentArea > maxArea) {
//                             maxArea = currentArea;
//                             bestY = yStart;
//                             bestX = xStart;
//                             shapesToExtract = tempShapes;
//                         }
//                         else if (currentArea == maxArea && currentArea > 0) {
//                             if (yStart < bestY || (yStart == bestY && xStart < bestX)) {
//                                 bestY = yStart;
//                                 bestX = xStart;
//                                 shapesToExtract = tempShapes;
//                             }
//                         }
//                     }
//                 }
    
//                 if (maxArea == 0)
//                     break;
    
//                 for (int shapeID : shapesToExtract) {
//                     if (!shapes[shapeID].isExtracted) {
//                         shapes[shapeID].isExtracted = true;
//                         totalExtractedArea += shapes[shapeID].area;
//                     }
//                 }
    
//                 extractionTurns++;
//             }
    
//             return {extractionTurns, totalExtractedArea};
//         }
//     };
    
//     int main() {
//         ios::sync_with_stdio(false);
//         cin.tie(0);
    
//         int C, R, S, N;
//         cin >> C >> R >> S >> N;
    
//         GridManager gridManager(R, C, S, N);
    
//         for (int i = 0; i < N; i++) {
//             int x1, y1, x2, y2;
//             cin >> x1 >> y1 >> x2 >> y2;
//             gridManager.addWall(x1, y1, x2, y2);
//         }
    
//         gridManager.identifyShapes();
    
//         pair<int, int> result = gridManager.extractShapes();
    
//         cout << result.first << " " << result.second;
    
//         return 0;
//     }


// 4) Snake & ladder
// struct SnakeOrLadder {
//     int start;
//     int end;
//     string type; // "Snake" or "Ladder"
// };

// bool bfs_simulation(const vector<int>& die_rolls, const map<int, int>& board, int final_position) {
//     set<int> current_positions;
//     current_positions.insert(1);

//     for (int roll : die_rolls) {
//         set<int> next_positions;
//         for (int pos : current_positions) {
//             int new_pos = pos + roll;
//             if (new_pos > 100) {
//                 new_pos = pos; // Can't move beyond 100
//             } else {
//                 // Follow snakes and ladders
//                 while (board.count(new_pos)) {
//                     new_pos = board.at(new_pos);
//                 }
//             }
//             next_positions.insert(new_pos);
//         }
//         current_positions = next_positions;
//     }

//     // Check if final position is among possible positions and is valid
//     return current_positions.count(final_position) && !board.count(final_position);
// }

// int main() {
//     int N;
//     cin >> N;

//     vector<SnakeOrLadder> snakes_ladders;
//     map<int, int> board; // key: start cell, value: end cell
//     for (int i = 0; i < N; ++i) {
//         int start, end;
//         cin >> start >> end;
//         SnakeOrLadder s;
//         s.start = start;
//         s.end = end;
//         if (start > end) {
//             s.type = "Snake";
//         } else {
//             s.type = "Ladder";
//         }
//         snakes_ladders.push_back(s);
//         board[start] = end;
//     }

//     // Read die rolls
//     string die_input_line;
//     cin.ignore(); // Ignore the newline after N and the snakes/ladders
//     getline(cin, die_input_line);

//     vector<int> die_rolls;
//     stringstream ss(die_input_line);
//     int num;
//     while (ss >> num) {
//         die_rolls.push_back(num);
//     }

//     int final_position;
//     cin >> final_position;

//     // Simulate game without any switch using BFS
//     if (bfs_simulation(die_rolls, board, final_position)) {
//         cout << "Not affected";
//         return 0;
//     }

//     // Try switching each snake or ladder
//     bool found = false;
//     for (const SnakeOrLadder& s : snakes_ladders) {
//         // Create a modified board
//         map<int, int> modified_board = board;

//         // Remove the original snake or ladder
//         modified_board.erase(s.start);

//         // Switch the snake or ladder
//         SnakeOrLadder switched;
//         switched.start = s.end;
//         switched.end = s.start;
//         if (s.type == "Snake") {
//             switched.type = "Ladder";
//         } else {
//             switched.type = "Snake";
//         }

//         // Avoid placing a snake or ladder on cell 1
//         if (switched.start == 1) continue;

//         modified_board[switched.start] = switched.end;

//         // Simulate the game with the modified board using BFS
//         if (bfs_simulation(die_rolls, modified_board, final_position)) {
//             // Output the switched object
//             cout << switched.type << " " << switched.start << " " << switched.end;
//             found = true;
//             break;
//         }
//     }

//     if (!found) {
//         cout << "Not reachable";
//     }

//     return 0;
// }



// 5) Star 
// typedef pair<int, int> Point;

// // Function to normalize the shape to a canonical form
// vector<Point> normalize_shape(vector<Point> shape) {
//     if (shape.empty()) return shape;
    
//     // Find minimum x and y
//     int min_x = shape[0].first, min_y = shape[0].second;
//     for (const auto &p : shape) {
//         min_x = min(min_x, p.first);
//         min_y = min(min_y, p.second);
//     }
    
//     // Translate points
//     for (auto &p : shape) {
//         p.first -= min_x;
//         p.second -= min_y;
//     }
    
//     // Sort points lexicographically
//     sort(shape.begin(), shape.end());
//     return shape;
// }

// // Function to rotate a shape 90 degrees counterclockwise
// vector<Point> rotate_shape(const vector<Point> &shape) {
//     vector<Point> rotated;
//     for (const auto &p : shape) {
//         rotated.emplace_back(-p.second, p.first);
//     }
//     return normalize_shape(rotated);
// }

// // Generate all possible rotations of a shape
// set<vector<Point>> generate_all_rotations(vector<Point> shape) {
//     set<vector<Point>> rotations;
//     shape = normalize_shape(shape);
    
//     for (int i = 0; i < 4; ++i) {
//         rotations.insert(shape);
//         shape = rotate_shape(shape);
//     }
//     return rotations;
// }

// // Check if two shapes are equivalent under rotation
// bool are_shapes_equivalent(const vector<Point> &shape1, const vector<Point> &shape2) {
//     auto rotations1 = generate_all_rotations(shape1);
//     auto normalized_shape2 = normalize_shape(shape2);
    
//     return rotations1.count(normalized_shape2) > 0;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int N;
//     cin >> N;
//     vector<vector<Point>> earrings(N);
    
//     // Read all earrings
//     for (int i = 0; i < N; i++) {
//         int K;
//         cin >> K;
//         earrings[i].resize(K);
//         for (int j = 0; j < K; j++) {
//             cin >> earrings[i][j].first >> earrings[i][j].second;
//         }
//     }
    
//     // Find all matching pairs
//     vector<pair<int, int>> matching_pairs;
//     for (int i = 0; i < N; i++) {
//         for (int j = i + 1; j < N; j++) {
//             if (are_shapes_equivalent(earrings[i], earrings[j])) {
//                 matching_pairs.emplace_back(i + 1, j + 1);
//             }
//         }
//     }
    
//     // Print matching pairs
//     if (matching_pairs.empty()) {
//         cout << "No matching pairs" << endl;
//     } else {
//         sort(matching_pairs.begin(), matching_pairs.end());
//         for (size_t i = 0; i < matching_pairs.size(); ++i) {
//             cout << matching_pairs[i].first << " " << matching_pairs[i].second;
//             if (i < matching_pairs.size() - 1) {
//                 cout << " ";
//             }
//         }
//         cout << endl;
//     }
    
//     return 0;
// }


// 6) Loop Master

// class LoopMaster {
//     private:
//         vector<string> commands;
//         int totalLines;
    
//     public:
//         void readInput() {
//             cin >> totalLines;
//             cin.ignore(); // Clear newline
    
//             commands.resize(totalLines);
//             for (int i = 0; i < totalLines; i++) {
//                 getline(cin, commands[i]);
//             }
//         }
    
//         void processCommands() {
//             vector<int> loopCounts; // To track the current iteration of each loop
//             vector<int> loopLimits; // To track the total iterations for each loop
//             vector<int> loopStartIndices; // To track the starting index of each loop
    
//             int lineIndex = 0; // Current line index
//             while (lineIndex < totalLines) {
//                 string command = commands[lineIndex];
    
//                 if (command.find("for") != string::npos) {
//                     // Start of a new loop
//                     int iterations = stoi(command.substr(4, command.find("times") - 4));
//                     loopCounts.push_back(0); // Initialize current count
//                     loopLimits.push_back(iterations); // Set limit
//                     loopStartIndices.push_back(lineIndex); // Store start index
//                 } 
//                 else if (command == "do") {
//                     // Move to the next line
//                     lineIndex++;
//                     continue;
//                 } 
//                 else if (command == "done") {
//                     // End of the current loop
//                     if (!loopCounts.empty()) {
//                         loopCounts.back()++; // Increment the current loop count
//                         if (loopCounts.back() < loopLimits.back()) {
//                             // If not finished, go back to the start of the loop
//                             lineIndex = loopStartIndices.back() + 1;
//                         } else {
//                             // If finished, pop the loop
//                             loopCounts.pop_back();
//                             loopLimits.pop_back();
//                             loopStartIndices.pop_back();
//                         }
//                     }
//                 } 
//                 else if (command.find("continue") != string::npos) {
//                     // Handle continue statement
//                     int continueIteration = stoi(command.substr(9));
//                     if (!loopCounts.empty() && loopCounts.back() + 1 == continueIteration) {
//                         // Skip to the end of the current loop
//                         while (lineIndex < totalLines && commands[lineIndex] != "done") {
//                             lineIndex++;
//                         }
//                     }
//                 } 
//                 else if (command.find("break") != string::npos) {
//                     // Handle break statement
//                     int breakIteration = stoi(command.substr(6));
//                     if (!loopCounts.empty() && loopCounts.back() + 1 == breakIteration) {
//                         // Exit the current loop
//                         while (lineIndex < totalLines && commands[lineIndex] != "done") {
//                             lineIndex++;
//                         }
//                         // Pop the loop since we are breaking out of it
//                         loopCounts.pop_back();
//                         loopLimits.pop_back();
//                         loopStartIndices.pop_back();
//                     }
//                 } 
//                 else if (command.find("print") != string::npos) {
//                     // Handle print statement
//                     string output = command.substr(command.find("\"") + 1, 
//                                                    command.rfind("\"") - command.find("\"") - 1);
//                     cout << output << endl;
//                 }
    
//                 lineIndex++;
//             }
//         }
    
//         void solve() {
//             readInput();
//             processCommands();
//         }
//     };
    
//     int main() {
//         LoopMaster loopMaster;
//         loopMaster.solve();
//         return 0;
//     }







int main(){



    return 0;
}