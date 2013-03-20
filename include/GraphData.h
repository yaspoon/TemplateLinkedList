#ifndef GRAPHDATA_H
#define GRAPHDATA_H


class GraphData
{
    public:
        GraphData();
        GraphData(int inVertex1, int inVertex2, int inWeight);
        virtual ~GraphData();

        void setVertex1(int vertex);
        void setVertex2(int vertex);
        void setWeigth(int newWeight);

        int getVertex1();
        int getVertex2();
        int getWeight();

        void copyEdge( GraphData edge);
    protected:
    private:
        int vertex1;
        int vertex2;
        int weight;
};

#endif // GRAPHDATA_H
