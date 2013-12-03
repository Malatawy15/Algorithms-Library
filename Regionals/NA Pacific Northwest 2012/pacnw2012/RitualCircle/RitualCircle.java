import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class RitualCircle {
  public static final double EPS = 1e-6;
  
  public static boolean areCollinear(Point2D.Double a, Point2D.Double b, Point2D.Double c) {
    return (a.x * b.y - b.x * a.y) + (b.x * c.y - c.x * b.y) + (c.x * a.y - a.x * c.y) == 0;
  }
  
  // true iff a is between b and c on the same line
  public static boolean isInBetween(Point2D.Double a, Point2D.Double b, Point2D.Double c) {
    if (!areCollinear(a, b, c)) return false;
    return (a.distance(b) + a.distance(c) < b.distance(c) + EPS);
  }
  
  static Point2D.Double LLI(Point2D.Double a, Point2D.Double b, Point2D.Double c, Point2D.Double d) {
    Point2D.Double B = new Point2D.Double(b.x-a.x, b.y-a.y);
    Point2D.Double D = new Point2D.Double(c.x-d.x, c.y-d.y);
    Point2D.Double C = new Point2D.Double(c.x-a.x, c.y-a.y);
    double mult = (C.x*D.y-C.y*D.x)/(B.x*D.y-B.y*D.x);
    return new Point2D.Double(a.x + B.x*mult, a.y + B.y*mult);
  }

  public static Point2D.Double circleCenter(Point2D.Double a, Point2D.Double b, Point2D.Double c) {
    Point2D.Double B = new Point2D.Double((a.x+b.x)/2, (a.y+b.y)/2);
    Point2D.Double C = new Point2D.Double((a.x+c.x)/2, (a.y+c.y)/2);
    return LLI(B, new Point2D.Double(B.x+a.y-B.y, B.y+B.x-a.x), C, new Point2D.Double(C.x+a.y-C.y, C.y+C.x-a.x));
  }
  
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    
    outer: while (s.hasNextLine()) {
      List<Point2D.Double> included = new ArrayList<Point2D.Double>();
      String datline = s.nextLine() ;
      datline = datline.replaceAll(" none", "") ;
      String[] line = datline.split(" ");
      for (int i = 1; i < line.length; i++) {
        line[i] = line[i].substring(1, line[i].length() - 1);
        String[] nums = line[i].split(",");
        included.add(new Point2D.Double(Integer.parseInt(nums[0]), Integer.parseInt(nums[1])));
      }
      
      List<Point2D.Double> excluded = new ArrayList<Point2D.Double>();
      datline = s.nextLine() ;
      datline = datline.replaceAll(" none", "") ;
      line = datline.split(" ");
      for (int i = 1; i < line.length; i++) {
        line[i] = line[i].substring(1, line[i].length() - 1);
        String[] nums = line[i].split(",");
        excluded.add(new Point2D.Double(Integer.parseInt(nums[0]), Integer.parseInt(nums[1])));
      }
      
      if (included.size() < 2) {
        System.out.println(0);
        continue outer;
      }
      
      double best = 1e20;
      
      for (int i = 0; i < included.size(); i++) {
        Point2D.Double pt1 = included.get(i);
        inner: for (int j = i + 1; j < included.size(); j++) {
          Point2D.Double pt2 = included.get(j);
          if (pt1.equals(pt2)) continue;
          for (Point2D.Double pt3 : excluded) {
            if (isInBetween(pt3, pt1, pt2)) {
              System.out.println("The Orcs are close");
              continue outer;
            }
          }
          
          Line2D.Double l = new Line2D.Double(pt1, pt2);
          double goodEvents = 1e20; // add inc, drop exc
          double badEvents = -1e20; // drop inc, add exc
          
          for (Point2D.Double pt3 : included) {
            if (pt1.equals(pt3)) continue;
            if (pt2.equals(pt3)) continue;
            if (areCollinear(pt1, pt2, pt3)) {
              if (isInBetween(pt3, pt1, pt2)) continue;
              else continue inner;
            }
            
            Point2D.Double center = circleCenter(pt1, pt2, pt3);
            if (l.relativeCCW(pt3) > 0) { // left, drop inc
              badEvents = Math.max(badEvents, l.relativeCCW(center) * l.ptLineDist(center));
            } else { // right, add inc
              goodEvents = Math.min(goodEvents, l.relativeCCW(center) * l.ptLineDist(center));
            }
          }
          
          for (Point2D.Double pt3 : excluded) {
            if (areCollinear(pt1, pt2, pt3)) continue;
            
            Point2D.Double center = circleCenter(pt1, pt2, pt3);
            if (l.relativeCCW(pt3) > 0) { // left, drop exc
              goodEvents = Math.min(goodEvents, l.relativeCCW(center) * l.ptLineDist(center));
            } else { // right, add exc
              badEvents = Math.max(badEvents, l.relativeCCW(center) * l.ptLineDist(center));
            }
          }
          
          if (goodEvents < badEvents + EPS) continue inner;
          
          double dist;
          if (goodEvents > 0 && badEvents < 0) dist = 0;
          else dist = Math.min(Math.abs(goodEvents), Math.abs(badEvents));
          
          best = Math.min(best, Math.sqrt(dist * dist + pt1.distanceSq(pt2) / 4));
        }
      }
      
      if (best == 1e20) {
        System.out.println("The Orcs are close");
      } else {
        System.out.println(best);
      }
    }
  }
}
