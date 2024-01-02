package com.netz00.attendancemonitoringsystem.domain;


import jakarta.persistence.*;
import lombok.*;

import java.util.Date;

import static jakarta.persistence.GenerationType.SEQUENCE;

@Entity
@NoArgsConstructor
@AllArgsConstructor
@Getter
@Setter
@Table(name = "record")
public class Record {

    @Id
    @SequenceGenerator(name = "record_sequence", sequenceName = "record_sequence", allocationSize = 1)
    @GeneratedValue(strategy = SEQUENCE, generator = "record_sequence")
    @Column(name = "id", updatable = false)
    private Long id;

    @Setter(AccessLevel.NONE)
    @Column(name = "date_created")
    private Date dateCreated = new Date();

    @ManyToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "room_id", referencedColumnName = "id")
    Room room;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "student_id", referencedColumnName = "id")
    Student student;
}
