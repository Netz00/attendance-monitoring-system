package com.netz00.attendancemonitoringsystem.dto;

import com.fasterxml.jackson.annotation.JsonProperty;
import jakarta.validation.constraints.NotBlank;
import lombok.Data;

@Data
public class PostLendingDTO {

    @NotBlank(message = "The room name is required.")
    @JsonProperty("roomName")
    private String roomName;

    @NotBlank(message = "The student JMBAG is required.")
    @JsonProperty("studentJmbag")
    private String studentJmbag;
}
