--
-- PostgreSQL database dump
--

-- Dumped from database version 14.5
-- Dumped by pg_dump version 14.5

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: books; Type: TABLE; Schema: public; Owner: kodya
--

CREATE TABLE public.books (
    isbn character varying NOT NULL,
    book_name character varying NOT NULL,
    author character varying NOT NULL,
    publisher_id integer,
    publish_year integer,
    pages integer NOT NULL,
    price numeric NOT NULL,
    copies_amount integer NOT NULL
);


ALTER TABLE public.books OWNER TO kodya;

--
-- Name: books_themes; Type: TABLE; Schema: public; Owner: kodya
--

CREATE TABLE public.books_themes (
    isbn character varying NOT NULL,
    theme_id integer NOT NULL
);


ALTER TABLE public.books_themes OWNER TO kodya;

--
-- Name: copies; Type: TABLE; Schema: public; Owner: kodya
--

CREATE TABLE public.copies (
    inventory_num integer NOT NULL,
    isbn character varying NOT NULL,
    reader_card_num integer,
    borrow_date timestamp without time zone,
    return_date timestamp without time zone
);


ALTER TABLE public.copies OWNER TO kodya;

--
-- Name: publishers; Type: TABLE; Schema: public; Owner: kodya
--

CREATE TABLE public.publishers (
    publisher_id integer NOT NULL,
    publisher_name character varying,
    publish_place character varying
);


ALTER TABLE public.publishers OWNER TO kodya;

--
-- Name: publishers_publisher_id_seq; Type: SEQUENCE; Schema: public; Owner: kodya
--

CREATE SEQUENCE public.publishers_publisher_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.publishers_publisher_id_seq OWNER TO kodya;

--
-- Name: publishers_publisher_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: kodya
--

ALTER SEQUENCE public.publishers_publisher_id_seq OWNED BY public.publishers.publisher_id;


--
-- Name: readers; Type: TABLE; Schema: public; Owner: kodya
--

CREATE TABLE public.readers (
    reader_card_num integer NOT NULL,
    last_name character varying NOT NULL,
    first_name character varying NOT NULL,
    middle_name character varying,
    birth_date date,
    phone_number character varying
);


ALTER TABLE public.readers OWNER TO kodya;

--
-- Name: readers_reader_card_num_seq; Type: SEQUENCE; Schema: public; Owner: kodya
--

CREATE SEQUENCE public.readers_reader_card_num_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.readers_reader_card_num_seq OWNER TO kodya;

--
-- Name: readers_reader_card_num_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: kodya
--

ALTER SEQUENCE public.readers_reader_card_num_seq OWNED BY public.readers.reader_card_num;


--
-- Name: themes; Type: TABLE; Schema: public; Owner: kodya
--

CREATE TABLE public.themes (
    theme_id integer NOT NULL,
    theme_name character varying
);


ALTER TABLE public.themes OWNER TO kodya;

--
-- Name: themes_theme_id_seq; Type: SEQUENCE; Schema: public; Owner: kodya
--

CREATE SEQUENCE public.themes_theme_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.themes_theme_id_seq OWNER TO kodya;

--
-- Name: themes_theme_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: kodya
--

ALTER SEQUENCE public.themes_theme_id_seq OWNED BY public.themes.theme_id;


--
-- Name: publishers publisher_id; Type: DEFAULT; Schema: public; Owner: kodya
--

ALTER TABLE ONLY public.publishers ALTER COLUMN publisher_id SET DEFAULT nextval('public.publishers_publisher_id_seq'::regclass);


--
-- Name: readers reader_card_num; Type: DEFAULT; Schema: public; Owner: kodya
--

ALTER TABLE ONLY public.readers ALTER COLUMN reader_card_num SET DEFAULT nextval('public.readers_reader_card_num_seq'::regclass);


--
-- Name: themes theme_id; Type: DEFAULT; Schema: public; Owner: kodya
--

ALTER TABLE ONLY public.themes ALTER COLUMN theme_id SET DEFAULT nextval('public.themes_theme_id_seq'::regclass);


--
-- Data for Name: books; Type: TABLE DATA; Schema: public; Owner: kodya
--

COPY public.books (isbn, book_name, author, publisher_id, publish_year, pages, price, copies_amount) FROM stdin;
9785171132354	The Green Mile	Stephen King	1	2019	384	500	0
9785699874453	Programming C++	Vasilev Alexey	2	2018	368	700	0
9785389074354	Harry Potter and the Philosopher stone	J.K.Rawling	5	2022	450	592	0
9785171542016	The Lord of the Rings	J.R.R.Tolkien	1	2023	752	1300	0
9785170940707	The Long Walk	Stephen King	1	2019	352	500	0
9785041074173	Terry Pratchett	Good Omens	2	2019	512	400	0
9785488029637	Math. Collection of tasks	M.I. Scanavi	4	2012	624	500	0
5280004251	The Master and Margarita	Michael Bulgakov	8	1988	384	250	0
9785171123895	Pride and Prejudice	Jane Austen	1	2020	416	274	0
9785171128470	Carrie	Stephen King	1	2018	320	400	2
9785367035940	Cosmos	Carl Sagan	3	2015	447	400	1
9785170817603	Hobbit	J.R.R.Tolkien	1	2023	256	570	1
9785907539051	Demon Slayer	Koyoharu Gotouge	7	2022	192	500	1
9785040986842	The Picture of Dorian Gray	Oscar Wilde	2	2021	256	350	1
9785171051235	The Colorado kid	Stephen King	1	2019	192	250	3
9785389084230	Attack on titan	Hajime Isayama	6	2022	384	510	2
9785041077198	The Catcher in the Rye	J.D. Salinger	2	2021	320	300	1
\.


--
-- Data for Name: books_themes; Type: TABLE DATA; Schema: public; Owner: kodya
--

COPY public.books_themes (isbn, theme_id) FROM stdin;
9785389084230	1
9785907539051	1
9785171128470	3
9785171132354	3
9785389074354	3
9785171542016	3
5280004251	3
9785907539051	3
9785171128470	5
9785171132354	5
9785170940707	5
9785171132354	6
9785171051235	6
9785699874453	7
9785488029637	7
9785367035940	7
9785171123895	8
5280004251	8
\.


--
-- Data for Name: copies; Type: TABLE DATA; Schema: public; Owner: kodya
--

COPY public.copies (inventory_num, isbn, reader_card_num, borrow_date, return_date) FROM stdin;
10002	9785171128470	\N	\N	\N
10001	9785171128470	5	2023-11-22 05:18:00	\N
30001	9785170817603	5	2023-11-22 05:20:00	\N
20001	9785367035940	3	2023-11-22 05:22:00	\N
50009	9785040986842	\N	\N	\N
40001	9785907539051	1	2023-11-22 05:25:00	\N
98272	9785389084230	\N	\N	\N
98271	9785389084230	\N	\N	\N
67891	9785041077198	\N	\N	\N
71091	9785171051235	7	2023-11-22 05:30:00	\N
78901	9785171051235	9	2023-11-22 05:30:00	\N
70231	9785171051235	2	2023-11-22 05:30:00	2023-11-22 05:33:00
\.


--
-- Data for Name: publishers; Type: TABLE DATA; Schema: public; Owner: kodya
--

COPY public.publishers (publisher_id, publisher_name, publish_place) FROM stdin;
1	AST	Moscow
2	Eksmo	Moscow
3	Amphora	Saint Petersburg
4	Astrel	Saint Petersburg
5	Mahaon	Moscow
6	Azbuka	Saint Petersburg
7	Istari comic	Moscow
8	Fiction	Moscow
9	Dropha	Moscow
\.


--
-- Data for Name: readers; Type: TABLE DATA; Schema: public; Owner: kodya
--

COPY public.readers (reader_card_num, last_name, first_name, middle_name, birth_date, phone_number) FROM stdin;
1	Ivanov	Ivan	Ivanovich	1980-01-01	79991234567
2	Petrov	Petr	Petrovich	1975-05-15	79992345678
3	Sidorova	Anna	Aleksandrovna	1998-11-20	79993456789
4	Kukartseva	Olga	Dmitrievna	2002-08-13	79139828640
5	Kuznetsova	Ekaterina	Sergeevna	2003-04-03	79994567890
6	Nikolaev	Nikolay	Nikolaevich	2000-12-12	79995678901
7	Smirnov	Andrey	Victorovich	1995-06-25	79997890123
8	Kozlova	Aleksandra	Igorevna	1992-07-07	79998901234
9	Fedorov	Alexey	Andreevich	1999-03-17	79999012345
10	Elena	Morozova	Vladimirovna	1990-11-05	79990123456
\.


--
-- Data for Name: themes; Type: TABLE DATA; Schema: public; Owner: kodya
--

COPY public.themes (theme_id, theme_name) FROM stdin;
1	Manga
3	Fantasy
5	Horror
6	Detective
7	Education
8	Romance novels
\.


--
-- Name: publishers_publisher_id_seq; Type: SEQUENCE SET; Schema: public; Owner: kodya
--

SELECT pg_catalog.setval('public.publishers_publisher_id_seq', 9, true);


--
-- Name: readers_reader_card_num_seq; Type: SEQUENCE SET; Schema: public; Owner: kodya
--

SELECT pg_catalog.setval('public.readers_reader_card_num_seq', 10, true);


--
-- Name: themes_theme_id_seq; Type: SEQUENCE SET; Schema: public; Owner: kodya
--

SELECT pg_catalog.setval('public.themes_theme_id_seq', 8, true);


--
-- Name: books books_pkey; Type: CONSTRAINT; Schema: public; Owner: kodya
--

ALTER TABLE ONLY public.books
    ADD CONSTRAINT books_pkey PRIMARY KEY (isbn);


--
-- Name: copies copies_pkey; Type: CONSTRAINT; Schema: public; Owner: kodya
--

ALTER TABLE ONLY public.copies
    ADD CONSTRAINT copies_pkey PRIMARY KEY (inventory_num);


--
-- Name: publishers publishers_pkey; Type: CONSTRAINT; Schema: public; Owner: kodya
--

ALTER TABLE ONLY public.publishers
    ADD CONSTRAINT publishers_pkey PRIMARY KEY (publisher_id);


--
-- Name: readers readers_pkey; Type: CONSTRAINT; Schema: public; Owner: kodya
--

ALTER TABLE ONLY public.readers
    ADD CONSTRAINT readers_pkey PRIMARY KEY (reader_card_num);


--
-- Name: themes themes_pkey; Type: CONSTRAINT; Schema: public; Owner: kodya
--

ALTER TABLE ONLY public.themes
    ADD CONSTRAINT themes_pkey PRIMARY KEY (theme_id);


--
-- Name: books books_publisher_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: kodya
--

ALTER TABLE ONLY public.books
    ADD CONSTRAINT books_publisher_id_fkey FOREIGN KEY (publisher_id) REFERENCES public.publishers(publisher_id);


--
-- Name: books_themes books_themes_isbn_fkey; Type: FK CONSTRAINT; Schema: public; Owner: kodya
--

ALTER TABLE ONLY public.books_themes
    ADD CONSTRAINT books_themes_isbn_fkey FOREIGN KEY (isbn) REFERENCES public.books(isbn);


--
-- Name: books_themes books_themes_theme_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: kodya
--

ALTER TABLE ONLY public.books_themes
    ADD CONSTRAINT books_themes_theme_id_fkey FOREIGN KEY (theme_id) REFERENCES public.themes(theme_id);


--
-- Name: copies copies_isbn_fkey; Type: FK CONSTRAINT; Schema: public; Owner: kodya
--

ALTER TABLE ONLY public.copies
    ADD CONSTRAINT copies_isbn_fkey FOREIGN KEY (isbn) REFERENCES public.books(isbn);


--
-- Name: copies copies_reader_card_num_fkey; Type: FK CONSTRAINT; Schema: public; Owner: kodya
--

ALTER TABLE ONLY public.copies
    ADD CONSTRAINT copies_reader_card_num_fkey FOREIGN KEY (reader_card_num) REFERENCES public.readers(reader_card_num);


--
-- PostgreSQL database dump complete
--

